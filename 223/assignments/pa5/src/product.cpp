#include "product.hpp"

Product::Product(LinkedList<std::string> cols) {
	uniq_id_ = cols.pop_front();
	product_name_ = cols.pop_front();
	brand_name_ = cols.pop_front();
	asin_ = cols.pop_front();
	category_ = cols.pop_front();
	upc_ean_code_ = cols.pop_front();
	list_price_ = cols.pop_front();

	selling_price_ = cols.pop_front();
	try {
		// remove leading "$"
		selling_price_f_ = std::stof(selling_price_.substr(1));
	} catch (...) {
		// if unable to parse, sort element to the end
		selling_price_f_ = -1;
	}

	quantity_ = cols.pop_front();
	model_number_ = cols.pop_front();
	about_product_ = cols.pop_front();
	product_specification_ = cols.pop_front();
	technical_details_ = cols.pop_front();
	shipping_weight_ = cols.pop_front();
	product_dimensions_ = cols.pop_front();
	image_ = cols.pop_front();
	variants_ = cols.pop_front();
	sku_ = cols.pop_front();
	product_url_ = cols.pop_front();
	stock_ = cols.pop_front();
	product_details_ = cols.pop_front();
	dimensions_ = cols.pop_front();
	color_ = cols.pop_front();
	ingredients_ = cols.pop_front();
	direction_to_use_ = cols.pop_front();
	is_amazon_seller_ = cols.pop_front();
	size_quantity_variant_ = cols.pop_front();
	product_description_ = cols.pop_front();
}

void Product::display() const {
	std::cout << "ID:               " << uniq_id_ << std::endl;
	std::cout << "Name:             " << product_name_ << std::endl;
	std::cout << "Brand:            " << brand_name_ << std::endl;
	std::cout << "ASIN:             " << asin_ << std::endl;
	std::cout << "Categories:       " << category_ << std::endl;
	std::cout << "UPC/EAN:          " << upc_ean_code_ << std::endl;
	std::cout << "List Price:       " << list_price_ << std::endl;
	std::cout << "Selling Price:    " << selling_price_ << std::endl;
	std::cout << "Quantity:         " << quantity_ << std::endl;
	std::cout << "Model Number:     " << model_number_ << std::endl;
	std::cout << "About:            " << about_product_ << std::endl;
	std::cout << "Specs:            " << product_specification_
		  << std::endl;
	std::cout << "Technical:        " << technical_details_ << std::endl;
	std::cout << "Shipping Weight:  " << shipping_weight_ << std::endl;
	std::cout << "Dimensions:       " << product_dimensions_ << std::endl;
	std::cout << "Image:            " << image_ << std::endl;
	std::cout << "Variants:         " << variants_ << std::endl;
	std::cout << "SKU:              " << sku_ << std::endl;
	std::cout << "URL:              " << product_url_ << std::endl;
	std::cout << "Stock:            " << stock_ << std::endl;
	std::cout << "Details:          " << product_details_ << std::endl;
	std::cout << "Dimensions:       " << dimensions_ << std::endl;
	std::cout << "Color:            " << color_ << std::endl;
	std::cout << "Ingredients:      " << ingredients_ << std::endl;
	std::cout << "Direction:        " << direction_to_use_ << std::endl;
	std::cout << "Is Amazon Seller: " << is_amazon_seller_ << std::endl;
	std::cout << "Size/Quantity:    " << size_quantity_variant_
		  << std::endl;
	std::cout << "Description:      " << product_description_ << std::endl;
}
