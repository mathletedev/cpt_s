#include "product.hpp"

Product::Product(LinkedList<std::string> cols) {
	uniq_id = cols.pop_front();
	product_name = cols.pop_front();
	brand_name = cols.pop_front();
	asin = cols.pop_front();
	category = cols.pop_front();
	upc_ean_code = cols.pop_front();
	list_price = cols.pop_front();

	selling_price = cols.pop_front();
	try {
		// remove leading "$"
		selling_price_f = std::stof(selling_price.substr(1));
	} catch (...) {
		// if unable to parse, sort element to the end
		selling_price_f = -1;
	}

	quantity = cols.pop_front();
	model_number = cols.pop_front();
	about_product = cols.pop_front();
	product_specification = cols.pop_front();
	technical_details = cols.pop_front();
	shipping_weight = cols.pop_front();
	product_dimensions = cols.pop_front();
	image = cols.pop_front();
	variants = cols.pop_front();
	sku = cols.pop_front();
	product_url = cols.pop_front();
	stock = cols.pop_front();
	product_details = cols.pop_front();
	dimensions = cols.pop_front();
	color = cols.pop_front();
	ingredients = cols.pop_front();
	direction_to_use = cols.pop_front();
	is_amazon_seller = cols.pop_front();
	size_quantity_variant = cols.pop_front();
	product_description = cols.pop_front();
}

void Product::display() const {
	std::cout << "ID:               " << uniq_id << std::endl;
	std::cout << "Name:             " << product_name << std::endl;
	std::cout << "Brand:            " << brand_name << std::endl;
	std::cout << "ASIN:             " << asin << std::endl;
	std::cout << "Categories:       " << category << std::endl;
	std::cout << "UPC/EAN:          " << upc_ean_code << std::endl;
	std::cout << "List Price:       " << list_price << std::endl;
	std::cout << "Selling Price:    " << selling_price << std::endl;
	std::cout << "Quantity:         " << quantity << std::endl;
	std::cout << "Model Number:     " << model_number << std::endl;
	std::cout << "About:            " << about_product << std::endl;
	std::cout << "Specs:            " << product_specification << std::endl;
	std::cout << "Technical:        " << technical_details << std::endl;
	std::cout << "Shipping Weight:  " << shipping_weight << std::endl;
	std::cout << "Dimensions:       " << product_dimensions << std::endl;
	std::cout << "Image:            " << image << std::endl;
	std::cout << "Variants:         " << variants << std::endl;
	std::cout << "SKU:              " << sku << std::endl;
	std::cout << "URL:              " << product_url << std::endl;
	std::cout << "Stock:            " << stock << std::endl;
	std::cout << "Details:          " << product_details << std::endl;
	std::cout << "Dimensions:       " << dimensions << std::endl;
	std::cout << "Color:            " << color << std::endl;
	std::cout << "Ingredients:      " << ingredients << std::endl;
	std::cout << "Direction:        " << direction_to_use << std::endl;
	std::cout << "Is Amazon Seller: " << is_amazon_seller << std::endl;
	std::cout << "Size/Quantity:    " << size_quantity_variant << std::endl;
	std::cout << "Description:      " << product_description << std::endl;
}
