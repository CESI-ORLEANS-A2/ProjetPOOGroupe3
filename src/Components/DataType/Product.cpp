#include "./Product.h"

Groupe3ProjetBlocPOO::Components::DataType::Product::Product() { }

Groupe3ProjetBlocPOO::Components::DataType::Product::Product(int id) {
	this->__id = id;
}

Groupe3ProjetBlocPOO::Components::DataType::Product::Product(DataRow^ row) {
	this->__id = Convert::ToInt32(row["id"]);
	this->__name = Convert::ToString(row["name"]);
	//this->__description = row->ItemArray[2]->ToString();
	this->__cost = Convert::ToInt32(row["cost"]);
	if (row->Table->Columns->Contains("type"))
		this->__type = Convert::ToString(row["type"]);
	if (row->Table->Columns->Contains("productType"))
		this->__productType = Convert::ToInt32(row["productType"]);
	if (row->Table->Columns->Contains("tax"))
		this->__tax = Convert::ToInt32(row["tax"]);
	this->__quantity = Convert::ToInt32(row["quantity"]);
	if (row->Table->Columns->Contains("stock"))
		this->__stock = Convert::ToInt32(row["stock"]);
}

Groupe3ProjetBlocPOO::Components::DataType::Product::Product(DataGridViewRow^ row) {
	this->__id = -1;
	if (row->Cells[0]->Value->ToString()->Length != 0) {
		this->__id = Convert::ToInt32(row->Cells[0]->Value->ToString());
	}
	this->__name = row->Cells[1]->Value->ToString();
	//this->__description = row->Cells[0]->Value->ToString();
	this->__cost = Convert::ToInt32(row->Cells[2]->Value->ToString());
	this->__type = row->Cells[3]->Value->ToString();
	if (row->Cells[4]->Value->ToString()->Length != 0)
	this->__tax = Convert::ToInt32(row->Cells[4]->Value->ToString());
	if (row->Cells[5]->Value->ToString()->Length != 0)
		this->__quantity = Convert::ToInt32(row->Cells[5]->Value->ToString());
	if (row->Cells[6]->Value->ToString()->Length != 0)
		this->__stock = Convert::ToInt32(row->Cells[6]->Value->ToString());
	if (row->Cells[7]->Value->ToString()->Length != 0)
		this->__productType = Convert::ToInt32(row->Cells[7]->Value->ToString());
}

Groupe3ProjetBlocPOO::Components::DataType::Product::Product(int id, Product^ product) {
	this->__id = id;
	this->__name = product->name();
	//this->__description = product->description();
	this->__cost = product->cost();
	this->__type = product->type();
	this->__tax = product->tax();
	this->__quantity = product->quantity();
	this->__stock = product->stock();
	this->__productType = product->productType();
}

Groupe3ProjetBlocPOO::Components::DataType::Product::Product(int id, String^ name, /*String^ description,*/ float cost, String^ type, float tax, int quantity, int stock) {
	this->__id = id;
	this->__name = name;
	//this->__description = description;
	this->__cost = cost;
	this->__type = type;
	this->__tax = tax;
	this->__quantity = quantity;
	this->__stock = stock;
}

int Groupe3ProjetBlocPOO::Components::DataType::Product::id(void) {
	return __id;
}

void Groupe3ProjetBlocPOO::Components::DataType::Product::name(String^ name) {
	__name = name;
}

String^ Groupe3ProjetBlocPOO::Components::DataType::Product::name() {
	return __name;
}


void Groupe3ProjetBlocPOO::Components::DataType::Product::cost(float cost) {
	__cost = cost;
}

float Groupe3ProjetBlocPOO::Components::DataType::Product::cost() {
	return __cost;
}

void Groupe3ProjetBlocPOO::Components::DataType::Product::type(String^ type) {
	__type = type;
}

String^ Groupe3ProjetBlocPOO::Components::DataType::Product::type() {
	return __type;
}

void Groupe3ProjetBlocPOO::Components::DataType::Product::productType(int productType) {
	__productType = productType;
}

int Groupe3ProjetBlocPOO::Components::DataType::Product::productType() {
	return __productType;
}

void Groupe3ProjetBlocPOO::Components::DataType::Product::tax(float tax) {
	__tax = tax;
}

float Groupe3ProjetBlocPOO::Components::DataType::Product::tax() {
	return __tax;
}

void Groupe3ProjetBlocPOO::Components::DataType::Product::quantity(int quantity) {
	__quantity = quantity;
}

int Groupe3ProjetBlocPOO::Components::DataType::Product::quantity(void) {
	return __quantity;
}

Windows::Forms::DataGridView^ Product::toDataGridView(array<Product^>^ product) {
	Windows::Forms::DataGridView^ table = gcnew Windows::Forms::DataGridView;

	table->Columns->Add("id", "id");
	table->Columns->Add("name", "name");
	table->Columns->Add("cost", "cost");
	table->Columns->Add("quantity", "quantity");
	table->Columns->Add("productType", "productType");

	for (int i = 0; i < product->Length; i++) {
		table->Rows->Add(product[i]->toDataGridViewRow());
	}
	return table;
}

Windows::Forms::DataGridViewRow^ Product::toDataGridViewRow() {
	Windows::Forms::DataGridView^ dataGridView = gcnew Windows::Forms::DataGridView();
	dataGridView->Columns->Add("id", "id");
	dataGridView->Columns->Add("name", "name");
	dataGridView->Columns->Add("cost", "cost");
	dataGridView->Columns->Add("quantity", "quantity");
	dataGridView->Columns->Add("productType", "productType");

	Windows::Forms::DataGridViewRow^ dataGridViewRow = dataGridView->Rows[0];

	dataGridViewRow->Cells[0]->Value = this->__id;
	dataGridViewRow->Cells[1]->Value = this->__name;
	dataGridViewRow->Cells[3]->Value = this->__cost;
	dataGridViewRow->Cells[4]->Value = this->__quantity;
	dataGridViewRow->Cells[5]->Value = this->__productType;

	return dataGridViewRow;
}

void Groupe3ProjetBlocPOO::Components::DataType::Product::stock(int stock) {
	__stock = stock;
}

int Groupe3ProjetBlocPOO::Components::DataType::Product::stock(void) {
	return __stock;
}

DataRow^ Groupe3ProjetBlocPOO::Components::DataType::Product::toDataRow() {
	DataRow^ row = Product::newDataRow();

	row["id"] = __id;
	row["name"] = __name;
	//row["description"] = __description;
	row["cost"] = __cost;
	row["type"] = __type;
	row["tax"] = __tax;
	row["quantity"] = __quantity;
	row["stock"] = __stock;
	row["producttype"] = __productType;

	return row;
}

array<Groupe3ProjetBlocPOO::Components::DataType::Product^>^ Groupe3ProjetBlocPOO::Components::DataType::Product::toArray(DataTable^ table) {
	array<Product^>^ products = gcnew array<Product^>(table->Rows->Count);

	for (int i = 0; i < table->Rows->Count; i++) {
		products[i] = gcnew Product(table->Rows[i]);
	}

	return products;
}

array<Groupe3ProjetBlocPOO::Components::DataType::Product^>^ Groupe3ProjetBlocPOO::Components::DataType::Product::toArray(DataRowCollection^ collection) {
	array<Product^>^ products = gcnew array<Product^>(collection->Count);

	for (int i = 0; i < collection->Count; i++) {
		products[i] = gcnew Product(collection[i]);
	}

	return products;
}

array<Groupe3ProjetBlocPOO::Components::DataType::Product^>^ Groupe3ProjetBlocPOO::Components::DataType::Product::toArray(DataGridViewRowCollection^ collection) {
	array<Product^>^ products = gcnew array<Product^>(collection->Count);

	for (int i = 0; i < collection->Count; i++) {
		products[i] = gcnew Product(collection[i]);
	}

	return products;
}

DataTable^ Groupe3ProjetBlocPOO::Components::DataType::Product::toDataTable(array<Product^>^ products) {
	DataTable^ dataTable = Product::dataTableSchema();
	dataTable->Clear();

	for (int i = 0; i < products->Length; i++) {
		dataTable->Rows->Add(products[i]->toDataRow());
	}
	return dataTable->Copy();
}

DataSet^ Groupe3ProjetBlocPOO::Components::DataType::Product::toDataSet(array<Product^>^ products, String^ tableName) {
	DataSet^ dataSet = gcnew DataSet();
	dataSet->Tables->Add(Product::toDataTable(products));
	dataSet->Tables[0]->TableName = tableName;
	return dataSet;
}

DataTable^ Groupe3ProjetBlocPOO::Components::DataType::Product::dataTableSchema() {
	if (__dataTableSchema->Columns->Count == 0) {
		__dataTableSchema->Columns->Add("id", int::typeid);
		__dataTableSchema->Columns->Add("name", String::typeid);
		//__dataTableSchema->Columns->Add("description", String::typeid);
		__dataTableSchema->Columns->Add("cost", float::typeid);
		__dataTableSchema->Columns->Add("type", String::typeid);
		__dataTableSchema->Columns->Add("tax", float::typeid);
		__dataTableSchema->Columns->Add("quantity", int::typeid);
		__dataTableSchema->Columns->Add("stock", int::typeid);
		__dataTableSchema->Columns->Add("producttype", int::typeid);
	}
	return __dataTableSchema;
}

DataRow^ Groupe3ProjetBlocPOO::Components::DataType::Product::newDataRow() {
	return __dataTableSchema->NewRow();
}

