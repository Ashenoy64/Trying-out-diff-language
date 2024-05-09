mod pizza_order{
    pub struct Pizza{
        pub dough:String,
        pub cheese:String,
        pub topping:String,
    }

    impl Pizza{
        pub fn lunch(topping:&str)->Pizza{
            Pizza {
                dough:String::from("Regular"),
                cheese:String::from("Mozzerella"),
                topping:String::from(topping),
            }
        }
    }

    pub mod help_customer{
        fn seat_at_table(){
            println!("Customer seated at table!");
        }

        pub fn take_order(){
            seat_at_table();
            let customer_pizza: super::Pizza = super::Pizza::lunch("veggie");
            serve_customer(customer_pizza);
        }

        fn serve_customer(cust_pizza:super::Pizza){
            println!("Customer servre with regular pizzza");
        }
    }
}

pub fn order_food(){
    crate::resturant::pizza_order::help_customer::take_order();
}