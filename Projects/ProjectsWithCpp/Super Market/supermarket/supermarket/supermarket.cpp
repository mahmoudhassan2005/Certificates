#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int maxProducts = 100; //Global variable (So i can use it in any part of the code -..-

struct Product { 
    string name;
    double price;
    int quantity;
};

// I used this & symbol bcz it is used to indicate that the numProducts parameter is passed by reference.
void addProduct(Product inventory[], int& numProducts, string& name, double price, int quantity) {
    if (numProducts < maxProducts) {
        Product newProduct;
        newProduct.name = name;
        newProduct.price = price;
        newProduct.quantity = quantity;

        inventory[numProducts] = newProduct;
        numProducts++;

        cout << "Product added successfully." << endl;
    }
    else {
        cerr << "Inventory is full. Cannot add more products." << endl;
        //cerr is used for writing error messages
    }
}

void displayInventory(const Product inventory[], int numProducts) {
    cout << "Inventory:" << endl;
    for (int i = 0; i < numProducts; ++i) {
        cout << "Name: " << inventory[i].name << ", Price: $" << inventory[i].price << ", Quantity: " << inventory[i].quantity << endl;
    }
}

void removeProduct(Product inventory[], int& numProducts, string& name) {
    bool productFound = false;
    for (int i = 0; i < numProducts; ++i) {
        if (inventory[i].name == name) {
            for (int j = i; j < numProducts - 1; ++j) {
                inventory[j] = inventory[j + 1];
            }
            numProducts--;
            productFound = true;
            break;
        }
    }

    if (productFound) {
        cout << "Product removed successfully." << endl;
    }
    else {
        cout << "Product not found in inventory." << endl;
    }
}

void runScrean() {
    string filename = "C:\\Users\\ahmed\\Desktop\\C++Projects\\Project\\Super Market\\supermarket\\inventory.txt";
    Product inventory[maxProducts];
    int numProducts = 0;

    ifstream data(filename);
    if (data.is_open()) {
        while (numProducts < maxProducts && data >> inventory[numProducts].name >> inventory[numProducts].price >> inventory[numProducts].quantity) {
            numProducts++;
        }
        data.close();
        cout << "Inventory loaded from file." << endl;
    }
    else {
        cerr << "Unable to open file. Starting with an empty inventory." << endl;
    }

    int choice;
    do {
        cout << "********************************************************\n";
        cout << "************************** Menu ************************\n";
        cout << "********************************************************\n";
        cout << "1. Display inventory\n";
        cout << "2. Add product\n";
        cout << "3. Remove product\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displayInventory(inventory, numProducts);
            break;
        case 2: {
            string name;
            double price;
            int quantity;

            cout << "Enter details for the product:\n";
            cout << "Name: ";
            cin >> name;
            cout << "Price: $";
            cin >> price;
            cout << "Quantity: ";
            cin >> quantity;

            addProduct(inventory, numProducts, name, price, quantity);
            break;
        }
        case 3: {
            string name;
            cout << "Enter the name of the product to remove: ";
            cin >> name;

            removeProduct(inventory, numProducts, name);
            break;
        }
        case 4:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (int i = 0; i < numProducts; ++i) {
            outputFile << inventory[i].name << " " << inventory[i].price << " " << inventory[i].quantity << endl;
        }
        outputFile.close();
        cout << "Inventory saved to file." << endl;
    }
    else {
        cerr << "Unable to open file to savethe inventory." << endl;
    }
}

int main() {
    runScrean();
    return 0;
}