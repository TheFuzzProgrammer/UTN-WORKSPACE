#pragma once
#include <string>
#include <vector>
#ifndef Vector
#define Vector std::vector
#endif
using namespace std;

namespace EPC7 {

	class Order {
	private:

		Vector<OrderDetail> detail;
		Provider provider;
		int orderNumber;
		Status status;


	public:
		Order(Provider _provider, Status _status, int _number) {
			this->orderNumber = _number;
			this->provider = _provider;
			this->status = _status;
	
		}

	public: 
		void updateStatus(bool = false, Date = Date());

		void addOrderDetail(OrderDetail _detail) {
			this->detail.push_back(_detail);
		}

		void setProvider(Provider _NewProvider) {
			this->provider = _NewProvider;
		}

		OrderDetail getDetailByIndex(int _index) {
			return this->detail[_index];
		}

		Vector<OrderDetail> getEntireDetail() {
			return this->detail;
		}
		Status getStatus() {
			return this->status;
		}

	};

	class OrderDetail {
		Product product;
		int quantity;

		public: OrderDetail(Product _product, int _quantity) {
			this->product = _product;
			this->quantity = _quantity;
		}
		public: float calculateAmmount() {

		}

	};

	class Provider {
		private:
			string name;
			Address address;
			ContactInfo contact;
			string socialReason;
			string IvaCondition;

		public: Provider(string _name, Address _address, ContactInfo _contact, string _socialReason, string _IvaCondition) {
			this->name = _name;
			this->address = _address;
			this->contact = _contact;
			this->socialReason = _socialReason;
			this->IvaCondition = _IvaCondition;

			}
		public: 
			void setName(string _name) {
				this->name = _name;
			}
			void setSocialReason(string _socialReason) {
				this->socialReason = _socialReason;
			}
			void setAddress(Address _address) {
				this->address = _address;
			};
			void setContactInfo(ContactInfo _contact) {
				this->contact = _contact;
			};
			void setIvaCondition(string _ivacond) {
				this->IvaCondition = _ivacond;
			};
			string getName() {
				return this->name;
			}

			string getAddress() {
				return this->address->ToString();
			}
			string getContact() {
				return this->contact->ToString();
			}
			string getSocialReason();
			string getIvaCondition();

	};

	class Address {

		string Country, Province, Street;
		string number;

		public: 
			Address(Vector<string> _reference, string _number) {
					this->Country = _reference[0];
					this->Province = _reference[1];
					this->Street = _reference[2];
					this->number = _number;
			}

		public:
			~Address() {
				delete this;
			}
		
		public: 
			string ToString() {
				return this->Street + " " + this->number + " " + this->Province + " " + this->Country;
			}
	};


	class Status {
		Date EndDate;
		bool delivered;

	};

	class Product {
		string name, description;
		float price;

		public: Product(string _name, string _description, float _price) {
			this->name = _name;
			this->description = _description;
			this->price = _price;
		}

		public: ~Product() {
			delete this;
		}
		
		public:
			void setPrice(float _newPrice) {
				this->price = _newPrice;
			}
			void setDescription(string _description) {
				this->description = _description;
			}

	};

	struct ContactInfo {
		string phone, fax;
		ContactInfo(string _phone, string _fax) {
			this->phone = _phone;
			this->fax = _fax;
		}
	};

	struct Date {
		int Year, Month, Day, Hour, Minutes;

		public: 
			Date() {

			}
		
		public: 
			~Date() {
				delete this;
			}

	};
}