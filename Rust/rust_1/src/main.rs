#![allow(unused)]

use std::io;
use std::process::Output;
use rand::Rng;
use std::io::{Write,BufReader,BufRead,ErrorKind};
use std::fs::File;
use std::cmp::Ordering;
use std::ops::Add;
use std::collections::HashMap;
mod resturant;

use crate::resturant::order_food;   

fn say_hello(){
    println!("hello");
}

fn get_sum(x:i32,y:i32)->i32{
    // return x+y;
    x+y
}

fn get_2(x:i32,y:i32)->(i32,i32){
    return (x+y,x-y);

}

//destroys the list in main
fn sum_list(v:Vec<i32>)->i32{
    let mut sum = 0;
    for i in v{
        sum+=i;
    }
    return sum;
}

fn ref_sum_list(v:&[i32])->i32{
    let mut sum = 0;
    for &i in v.iter(){
        sum+=&i;
    }
    return sum;
}

//generic
fn get_sum_gen<T:Add<Output=T>>(x:T,y:T)->T{
    return  x+y;
}

use std::thread;
use std::time::Duration;
use std::rc::Rc;
use std::cell::RefCell;
use std::sync::{Arc,Mutex};


fn main() {
    let t = thread::spawn(||{
        for i in 1..25{
            println!("Spawned Thread:{}",i);
            thread::sleep(Duration::from_millis(1));
        }
    });
    
    for i in 1..20{
        println!("Main Thread:{}",i);
        thread::sleep(Duration::from_millis(1));
    }

    t.join().unwrap();

    pub struct Bank{
        balance:f32,
    }
    fn withdraw(the_bank:&Arc<Mutex<Bank>>,amt:f32){
        let mut bank_ref = the_bank.lock().unwrap();
        if bank_ref.balance<5.00{
            println!("Cirrent balance is less {}",bank_ref.balance);
        }
        else {
            bank_ref.balance-=amt;
            println!("Customer withdrew {}",bank_ref.balance);
        }
    }

    fn customer(the_bank:&Arc<Mutex<Bank>>){
        withdraw(&the_bank,5.00);
    }

    let bank:Arc<Mutex<Bank>> = Arc::new(Mutex::new(Bank {balance:20.00}));


    //Box 

//     let b_int = Box::new(10);

//     println!("b_int1={}",b_int); 

//     struct TreeNode<T>{
//         pub left:Option<Box<TreeNode<T>>>,
//         pub right:Option<Box<TreeNode<T>>>,
//         pub key:T,
//     }

//     impl<T> TreeNode<T>{
//         pub fn new(key:T)->Self{
//             TreeNode{left:None,right:None,key:key}
//         }
    

//     pub fn left(mut self,node:TreeNode<T>)->Self{
//         self.left = Some(Box::new(node));
//         self
//     }

//     pub fn right(mut self,node:TreeNode<T>)->Self{
//         self.right = Some(Box::new(node));
//         self
//     }
// }


//     let node1 = TreeNode::new(1).left(TreeNode::new(2)).right(TreeNode::new(3));



    //closures or anonymus??
    // let can_vote = |age:i32|->bool{
    //     age >=18
    // };

    // println!("can he vote ? {}", can_vote(18));

    // let mut samp1 = 5;
    // let print_var =|| println!("sample 1 ={}",samp1);
    // print_var();
    // samp1=10;
    // let mut change_var=||samp1+=1;
    // change_var();
    // println!("sampl = {}",samp1);
    // samp1=100;
    // println!("sampl = {}",samp1);
    // // print_var();

    // fn use_func<Y>(a:i32,b:i32,func:Y)->i32
    // where Y:Fn(i32,i32)->i32{
    //     func(a,b)
    // }

    // let sum = |a:i32,b:i32| a+b;
    // let prod = |a:i32,b:i32| a*b;

    // println!("sum = {}",use_func(10, 20, sum));
    // println!("prod = {}",use_func(10, 20, prod));


    //iterator
    // let mut arr_it=[1,2,3,4];
    // for  val in arr_it.iter(){
    //     println!("{}",val);
    // }

    // let mut iter_1 = arr_it.iter();
    // println!("1st val {:?}",iter_1.next());


    // let path = "lines.txt";

    // let output = File::create(path);
    // let mut output = match output {
    //     Ok(file)=>file,
    //     Err(error)=>panic!("Problem creating file {:?}",error),
    // };



    // write!(output,"Just some\n Random words").expect("Failed to write to file");


    // let input = File::open(path).unwrap();
    // let buffered = BufReader::new(input);

    // for line in buffered.lines(){
    //     println!("{}",line.unwrap());
    // }

    // let output2 = File::create("rand.txt");

    // let output2 = match output2{
    //     Ok(file)=>file,
    //     Err(error)=>match error.kind() {
    //         ErrorKind::NotFound =>match File::create("rand.txt") {
    //             Ok(file) =>file,
    //             Err(e)=>panic!("Failed to create file"),
    //         },
    //         _=>panic!("Send help"),
    //     } ,
    // };
    
    
    
    































    // // Module
    // order_food();



    //struct

    // struct Cust{
    //     name:String,
    //     address:String,
    //     balance:f32,
    // }

    // let mut bob:Cust=Cust{name:String::from("BOB"),address:String::from("Earth"),balance:3.2};

    // bob.address=String::from("555 main st");



    // struct Rect<T,U>{
    //     length:T,
    //     height:U,
    // }

    // let rect=Rect{length:4,height:10.5};


    //trait
    // trait Shape{
    //     fn new(length:f32,width:f32)->Self;
    //     fn area(&self)->f32;
    // }

    // struct Rect{
    //     length:f32,
    //     height:f32,
    // }

    
    // struct Circle{
    //     radius:f32,
    // }

    // impl Shape for Rect {
    //     fn new(length:f32,width:f32)->Self {
    //         return Rect{length,height:width};
    //     }
    //     fn area(&self)->f32 {
    //         return self.length*self.height;
    //     }
    // }

    // impl Shape for Circle {
    //     fn new(length:f32,width:f32)->Self {
    //         return Circle{radius:length};
    //     }
    //     fn area(&self)->f32 {
    //         return self.radius*self.radius*3.141;
    //     }
    // }

    // let rect:Rect = Shape::new(10.0,12.0);
    // let circle:Circle = Shape::new(10.0,10.0);

    // println!("Rect area {}",rect.area());
    // println!("Circle area {}",circle.area());
    
    //Hashmap
    // let mut heroes = HashMap::new();
    // heroes.insert("superman", "clark kent");
    // heroes.insert("ironman", "tony stark");
    // heroes.insert("flash", "barry allen");

    // for (k,v) in heroes.iter(){
    //     println!("{} {} ",k,v)
    // }

    // println!("Length {}",heroes.len());
    // if heroes.contains_key("flash"){
    //     let name = heroes.get("flash");
    //     match name{
    //         Some(x)=>println!("{}",x),
    //         None=>println!("none"),
    //     }
    // }
    // println!("{}",heroes["flash"]);

    // say_hello();
    // println!("{}",get_sum(1,3));

    // let mut vec2 = vec![1,2,3,4];
    // println!("{:?}",ref_sum_list(&vec2));
    // println!("{}",sum_list(vec2));
    // println!("{}",vec2[0]);

    //generics

    // println!("{}",get_sum_gen(2, 3));
    // println!("{}",get_sum_gen(2.3, 32.2));


    //vectors

    // let vec1:Vec<i32> =  Vec::new();

    // let mut vec2 = vec![1,2,3,4];

    // vec2.push(2);
    // println!("{}",vec2[0]);

    // let second:&i32 = &vec2[1];

    // match vec2.get(1){
    //     Some(second)=>println!("exists"),
    //     None=>println!("dont exusrs"),
    // };

    // for i in &mut vec2{
    //     *i *= 2;
    // }

    // for i in &vec2{
    //     println!("{}",i);
    // }

    // println!("{}",vec2.len());

    // println!("{:?}",vec2.pop());

    // //casting
    // let a = 5;
    // let b:u8 = 10;

    // let c:u32 = (a as u32) + (b as u32) ;


    // //enum
    //  enum Days{
    //     M,
    //     T,
    //     W,
    //     Th,
    //     F,
    //     S,
    //     Sun,
    //  }

    //  impl Days{
    //     fn is_weekend(&self) -> bool{
    //         match self {
    //             Days::S | Days::Sun=> true,
    //             _=> false   
    //         }
    //     }
    //  }

    //  let today :Days = Days::M;

    //  match today{
    //     Days::M => println!("Nobody likes monday"),
    //     _=>println!("Mondaay is his big bro"),
    //  }

    // println!("{}",today.is_weekend());
    //Strings
        // let mut st1 = String::new();

        // st1.push('A');
        // st1.push_str(" Word");


        // for word in st1.split_whitespace(){
        //     println!("{}",word);
        // }

        // let st2 =st1.replace("A", "Hello");
        // println!("{}",st2);

        // let st3 = String::from("x r t b h k k a n c");

        // let mut v1:Vec<char> = st3.chars().collect();
        // v1.sort();
        // v1.dedup();

        // for char in v1{
        //     println!("{}",char);
        // }



        // let bytes = st1.as_bytes();
        // let st2 = &st1[0..3];

        // let st8 = st6 + &st7;
        // st1.clear();
    //One

    // println!("What is your name?");

    // let mut name:String= String::new();
    // let greeting= "Nice to meet you";
    // io::stdin().read_line(&mut name).expect("Didnt Recieve Input");
    // println!("Hello, {} {}",name.trim_end(),greeting);

    //Two 

    // const ONE_MIL: u32 = 1_00_0000;
    // const PI:f32 = 3.141459;
    // //shadowing
    // let age:&str = "47";
    // let mut age:u32 = age.trim().parse().expect("Age wasnt a number");
    
    //Placeholder
    // let _is_true:bool = true;
    
    
    // age = age + 1;
    // println!("Im {} and I want ${}",age,ONE_MIL);

    //Three
    // println!("Max u32 : {}",u32::MAX);

    //Four 
    // let num_1:f32 = 1.111111111111111; //6bits of precision
    // println!("f32 {}",num_1+0.111111111111111);
    //f64 has 14 digits of pricision

    //Five
    // let  a:u32 = 5;
    // let b:u32 = 6;

    // println!("+ {}",5+6);
    // println!("- {}",5-6);
    // println!("* {}",5*6);
    // println!("/ {}",5/6);
    // println!("% {}",5%6);

    //Six

    // let rand_num:i32 = rand::thread_rng().gen_range(1..101);
    // println!("Random {}",rand_num);

    // let age:i32 = 8;
    // if(age >= 1) && (age<=18){
    //     println!("Important Birthday!");
    // }
    // else if (age==21) || (age==50)
    // {
    //     println!("Important");
    // }
    // else if(age>=65)
    // {
    //     println!("Important");        
    // }
    // else {
    //     println!("Not Important");
    // }

    // //Ternary
    // let mut my_age = 47;
    // let can_vote = if my_age >=18 {true} else {false};

    // //Match
    // let age2:i32 = 8;
    // match  age2 {
    //     1..=18 =>println!("Importsnr"),
    //     21 | 50 => println!("Importnr"),
    //     65..=i32::MAX => println!("IMP"),
    //     _=>println!("Not imp"),
    // };

    // let new_age:i32 = 18;
    // match my_age.cmp(&new_age){
    //     Ordering::Less=>println!("no vote"),
    //     Ordering::Equal=>println!("vote"),
    //     Ordering::Greater=>println!("vote"),
    // };


    // let arr: [i32; 9] = [1,2,4,5,4,7,3,8,9];
    // println!("1 = {}, {}",arr[0],arr.len());

    // let mut i = 0;
    // loop {
    //     if arr[i]%2 == 0{
    //         i+=1;
    //         continue;
    //     }
    //     if arr[i]==9{
    //         break;
    //     }
    //     println!("val : {}",arr[i]);
    //     i+=1;

    // }

    // i=0;
    // while i < arr.len(){
    //     println!("val {}",arr[i]);
    //     i+=1;
    // } 

    // for val in arr.iter(){
    //     println!("Val {}",val);
    // }

    // let my_tuple:(u8,String,f64) = (1,"hello".to_string(),1.23);

    // println!("Name : {}",my_tuple.1);

    // let (v1,v2,v3) = my_tuple;
    // println!("Age : {} ",v1);

}
