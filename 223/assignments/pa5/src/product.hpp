#pragma once

#include "linked_list.hpp"
#include <string>

class Product {
	private:
		std::string uniq_id_, product_name_, brand_name_, asin_,
		    category_, upc_ean_code_, list_price_, selling_price_,
		    quantity_, model_number_, about_product_,
		    product_specification_, technical_details_,
		    shipping_weight_, product_dimensions_, image_, variants_,
		    sku_, product_url_, stock_, product_details_, dimensions_,
		    color_, ingredients_, direction_to_use_, is_amazon_seller_,
		    size_quantity_variant_, product_description_;
		float selling_price_f_;

	public:
		Product(LinkedList<std::string>);

		std::string id() const {
			return uniq_id_;
		}
		std::string name() const {
			return product_name_;
		}
		std::string category() const {
			return category_;
		}
		float price() const {
			return selling_price_f_;
		}
		std::string price_s() const {
			return selling_price_;
		}

		void display() const;
};
