use std::io;
use std::process;
use std::io::Write;
mod blockchain;

fn main() {
    let mut miner_addr =String::new();
    let mut difficulty = String::new();
    let mut choice =String::new();

    println!("Input a miner Address");

    io::stdout().flush();
    io::stdin().read_line(&mut miner_addr);

    println!("Difficulty:");
    io::stdout().flush();
    io::stdin().read_line(&mut difficulty);

    let diff = difficulty.trim().parse::<u32>().expect("We need a Integer");

    println!("Generating Genesis Block!");

    let mut chain = blockchain::Chain::new(miner_addr.trim().to_string(),diff);
    

    loop{
        println!("-----------Menue-----------");
        println!("1. New Transaction");
        println!("2. Mine Block");
        println!("3. Change Difficulty");
        println!("4. Change Reward");
        println!("0. Exit ");
        print!("Enter Your Choice: ");
        io::stdout().flush();
        io::stdin().read_line(&mut choice);
        println!("");

        match choice.trim().parse::<u32>().unwrap(){
            0=>{
                println!("Exiting");
                process::exit(0);
            },
            1=>{
                let mut sender= String::new();
                let mut receiver= String::new();
                let mut amt= String::new();

                print!("Enter Sender address:");
                io::stdout().flush();
                io::stdin().read_line(&mut sender);

                print!("Enter Receiver address:");
                io::stdout().flush();
                io::stdin().read_line(&mut receiver);


                print!("Enter amount:");
                io::stdout().flush();
                io::stdin().read_line(&mut amt);

                let res = chain.new_transaction(sender.trim().to_string(),receiver.trim().to_string(), amt.trim().parse::<f32>().unwrap());
                
                match res{
                    true=>println!("Transaction Successfull!"),
                    false=>println!("Transaction Failed!"),
                };
                
            },
            2=>{
                println!("Generating Block");
                let res = chain.generate_new_block();
                match res{
                    true=>println!("Block Generated Successfully"),
                    false=>println!("Block Generation failes"),
                }
            },
            3=>{
                let mut n_diff = String::new();
                print!("Enter New Difficulty:");
                io::stdout().flush();
                io::stdin().read_line(&mut n_diff);
                let res = chain.update_difficulty(n_diff.trim().parse::<u32>().unwrap());
                match  res {
                    true => println!("Updated the difficulty"),
                    false => println!("Unable to Update difficulty"),
                }
            },
            4=>{
                let mut n_reward = String::new();
                print!("Enter New Reward:");
                io::stdout().flush();
                io::stdin().read_line(&mut n_reward);
                let res = chain.update_difficulty(n_reward.trim().parse::<u32>().unwrap());
                match  res {
                    true => println!("Updated the reward"),
                    false => println!("Unable to Update reward"),
                } 
            },
            _=>{println!("\tInvalid Option Please try Again\t")},
        };

    }


}
