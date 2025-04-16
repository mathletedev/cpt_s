#pragma once

#include "linked_list.hpp"
#include <string>

class Product {
	public:
		std::string uniq_id, product_name, brand_name, asin, category,
		    upc_ean_code, list_price, selling_price, quantity,
		    model_number, about_product, product_specification,
		    technical_details, shipping_weight, product_dimensions,
		    image, variants, sku, product_url, stock, product_details,
		    dimensions, color, ingredients, direction_to_use,
		    is_amazon_seller, size_quantity_variant,
		    product_description;

		Product(LinkedList<std::string>);

		void display() const;
};
