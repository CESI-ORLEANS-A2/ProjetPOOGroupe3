#include "./ProductsService.h"


ProductService::ProductService(Database^database) {

	this->__database = database;

	Dictionary<String^, String^>^ productSchema = gcnew Dictionary<String^, String^>();
	productSchema->Add("id", "INT PRIMARY KEY AUTO_INCREMENT");
	productSchema->Add("name", "VARCHAR(100)");
	productSchema->Add("description", "VARCHAR(100)");
	productSchema->Add("cost", "FLOAT NOT NULL");
	productSchema->Add("quantity", "INT NOT NULL");
	productSchema->Add("productType", "VARCHAR(100) FOREIGN KEY REFERENCE ");
	this->__database->createTable("product", productSchema);

	Dictionary<String^, String^>^ productTypeSchema = gcnew Dictionary<String^, String^>();
	productTypeSchema->Add("productType", "VARCHAR(100) PRIMARY KEY");
	productTypeSchema->Add("rateTVA", "INT NOT NULL");
	this->__database->createTable("productType", productTypeSchema);
}

Product^ ProductService::getProduct(int id)
{
	return gcnew Product(this->__database->runQuery(ProductRequestMapping::getProduct(id))->Rows[0]);
}

Product^ ProductService::getProduct(Product^product)
{
	return gcnew Product(this->__database->runQuery(ProductRequestMapping::getProduct(product->id()))->Rows[0]);
}

array<Product^>^ ProductService::getProducts()
{
	Data::DataTable^ product = this->__database->runQuery(ProductRequestMapping::getProducts());
	return Product::toArray(product->Rows);
}

array<Product^>^ ProductService::getProducts(int rows)
{
	Data::DataTable^ product = this->__database->runQuery(ProductRequestMapping::getProducts(rows));
	return Product::toArray(product->Rows);
}

array<Product^>^ ProductService::getOrderProducts(int limit , int id)
{
	Data::DataTable^ product = this->__database->runQuery(ProductRequestMapping::getOrderProducts(limit , id));
	return Product::toArray(product->Rows);
}

Product^ ProductService::addProduct(Product^product) {
	int id = Convert::ToInt32(this->__database->runScalar(ProductRequestMapping::addProduct(product->name(),  product->cost(),product->quantity())));;
	return gcnew Product(id,product);
}

Product^ ProductService::addProduct(String^name,  float cost, int quantity){
	int id = Convert::ToInt32(this->__database->runScalar(ProductRequestMapping::addProduct(name, cost,quantity)));
	Product^ product = gcnew Product(id);
	product->name(name);
	product->quantity(quantity);
	product->cost(cost);
	return product;
}

Product^ ProductService::addOrderProduct(int productId, int orderId)
{
	Windows::Forms::DataGridView^ dataGridView = gcnew Windows::Forms::DataGridView();
	Windows::Forms::DataGridViewRowCollection^ dataGridViewRowCollection = gcnew Windows::Forms::DataGridViewRowCollection(dataGridView);
	Windows::Forms::DataGridViewRow^ dataGridViewRow = gcnew Windows::Forms::DataGridViewRow();
	for (int i = 0; i < dataGridView->ColumnCount; i++) {
		if (dataGridView->Columns[i]->Name == "quantity") {
			for (int j = 0 ; ;j++)
			if (Convert::ToInt32(dataGridViewRow->Cells[i]->Value) > 0) {
				int id = Convert::ToInt32(this->__database->runScalar(ProductRequestMapping::addOrderProduct(productId, orderId)));
			}
		}
	}
}

Product^ ProductService::addProduct(String^ name,  float cost) {
	int id = Convert::ToInt32(this->__database->runScalar(ProductRequestMapping::addProduct(name, cost)));
	Product^ product = gcnew Product(id);
	product->name(name);
	product->cost(cost);
	return product;
}


Product^ ProductService::updateProduct(Product^product) {
	this->__database->runQuery(ProductRequestMapping::updateProduct(product->id(),product->name(),product->cost(),product->quantity()))->Rows[0];
	return gcnew Product(this->__database->runQuery(ProductRequestMapping::getProduct(product->id()))->Rows[0]);
}

Product^ ProductService::updateProduct(int id, String^ name, String^ description, float cost, int stock) {
	this->__database->runQuery(ProductRequestMapping::updateProduct(id, name, cost, stock))->Rows[0];
	return gcnew Product(this->__database->runQuery(ProductRequestMapping::getProduct(id))->Rows[0]);
}


Product^ ProductService::removeProduct(Product^product) {
	Product^ newProduct = gcnew Product(this->__database->runQuery(ProductRequestMapping::deleteProduct(product->id()))->Rows[0]);
	return newProduct;
}

Product^ ProductService::removeProduct(int id) {
	Product^product = gcnew Product(this->__database->runQuery(ProductRequestMapping::getProduct(id))->Rows[0]);
	this->__database->runQuery(ProductRequestMapping::deleteProduct(id));
	return product;
}

Product^ ProductService::removeOrderProduct(int id)
{
	Product^ product = gcnew Product(this->__database->runQuery(ProductRequestMapping::getOrderProducts(id))->Rows[0]);
	this->__database->runQuery(ProductRequestMapping::deleteOrderProduct(id));
	return product;
}
