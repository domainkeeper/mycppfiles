#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Product {
private:
	int productId;
	string productName;
	double price;

public:
	Product(int id, const string& name, double productPrice)
		: productId(id), productName(name), price(productPrice) {}

	double calculatePrice() const {
		return price;
	}

	double calculatePrice(double discountPercentage) const {
		return price - (price * discountPercentage / 100.0);
	}

	double calculatePrice(double discountPercentage, double deliveryCharge) const {
		return calculatePrice(discountPercentage) + deliveryCharge;
	}

	void display() const {
		cout << "Product ID: " << productId << '\n'
			 << "Product Name: " << productName << '\n'
			 << fixed << setprecision(2)
			 << "Original Price: " << calculatePrice() << '\n'
			 << "Price after 10% discount: " << calculatePrice(10.0) << '\n'
			 << "Price after 10% discount and delivery charge of 50.00: "
			 << calculatePrice(10.0, 50.0) << "\n\n";
	}
};

int main() {
	int numberOfProducts;
	cout << "Enter the number of products: ";
	cin >> numberOfProducts;

	if (numberOfProducts <= 0) {
		cout << "Number of products must be positive.\n";
		return 0;
	}

	Product** products = new Product*[numberOfProducts];

	for (int i = 0; i < numberOfProducts; ++i) {
		int id;
		string name;
		double productPrice;

		cout << "\nEnter details for product " << i + 1 << ":\n";
		cout << "Product ID: ";
		cin >> id;
		cin.ignore();
		cout << "Product Name: ";
		getline(cin, name);
		cout << "Price: ";
		cin >> productPrice;

		products[i] = new Product(id, name, productPrice);
	}

	cout << "\nProduct Details\n===============\n";
	for (int i = 0; i < numberOfProducts; ++i) {
		products[i]->display();
		delete products[i];
	}

	delete[] products;
	return 0;
}
