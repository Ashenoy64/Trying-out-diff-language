extern crate serde;
extern crate serde_derive;
extern crate serde_json;
extern crate sha2;


use serde_derive::Serialize;
use sha2::{Digest,Sha256};
use std::fmt::Write;
use chrono::prelude::*;

#[derive(Debug,Clone,Serialize)]
struct Transaction{
    sender:String,
    reciever:String,
    amount:f32,
}

#[derive(Serialize,Debug)]
pub struct BlockHeader{
    timestamp:i64,
    nounce:u32,
    pre_hash:String,
    merkle:String,
    difficulty:u32,
}


#[derive(Serialize,Debug)]
pub struct Block{
    header:BlockHeader,
    count:u32,
    transaction:Vec<Transaction>,
}

pub struct Chain {
    chain:Vec<Block>,
    curr_trans:Vec<Transaction>,
    difficulty:u32,
    miner_addr:String,
    reward:f32,
}

impl Chain{
    pub fn new(miner_addr:String,difficulty:u32)->Chain{
        let mut chain = Chain{
            chain:Vec::new(),
            curr_trans:Vec::new(),
            difficulty,
            miner_addr,
            reward:100.0,
        };
        chain.generate_new_block();
        return chain;
    }

    pub fn new_transaction(&mut self,sender:String,reciever:String,amount:f32)->bool{
        self.curr_trans.push(Transaction{
            sender,
            reciever,
            amount,
        });
        return true;
    }

    pub fn last_hash(&self)->String{
        let block = match self.chain.last(){
            Some(block) =>block,
            None=>return String::from_utf8(vec![48;64]).unwrap()
        };
        Chain::hash(&block.header)
    }   

    pub fn update_difficulty(&mut self, difficulty:u32)->bool{
        self.difficulty = difficulty;
        true
    }

    pub fn update_reward(&mut self, reward:f32)->bool{
        self.reward = reward;
        true
    }

    pub fn generate_new_block(&mut self)->bool{
        let header = BlockHeader{
            timestamp:Utc::now().timestamp_millis(),
            nounce:0,
            pre_hash:self.last_hash(),
            difficulty:self.difficulty,
            merkle:String::new(),
        };

        let reward_trans = Transaction{
            sender:String::from("Root"),
            reciever:self.miner_addr.clone(),
            amount:self.reward,
        };

        let mut block = Block{
            header,
            count:0,
            transaction:vec![]
        };

        block.transaction.push(reward_trans);
        block.transaction.append(&mut self.curr_trans);
        block.count = block.transaction.len() as u32;
        block.header.merkle = Chain::get_merkle(block.transaction.clone());
        Chain::proof_of_work(&mut block.header);

        println!("{:#?}",&block);
        self.chain.push(block);

        true

    }

    fn get_merkle(curr_trans:Vec<Transaction>)->String{
        let mut merkle = Vec::new();

        for t in &curr_trans{
            let hash = Chain::hash(t);
            merkle.push(hash);
        }

        if merkle.len()%2==1{
            let last = merkle.last().cloned().unwrap();
            merkle.push(last);
        }

        while merkle.len()>1 {
            let mut h1 =  merkle.remove(0);
            let mut h2 =  merkle.remove(0);

            h1.push_str(&mut h2);
            let nh = Chain::hash(&h1);
            merkle.push(nh);
        }

        merkle.pop().unwrap()
    }

    pub fn proof_of_work(header:&mut BlockHeader){
        loop{
            let hash = Chain::hash(header);
            let slice = &hash[..header.difficulty as usize];

            match slice.parse::<u32>(){
                Ok(val)=>{
                    if val!=0{
                        header.nounce+=1;
                    }
                    else{
                        println!("Block hash: {}",hash);
                        break;
                    }
                },
                Err(_)=>{
                    header.nounce+=1;
                    continue;
                }
            };
        }


    }

    pub fn hash<T:serde :: Serialize>(item:&T)->String{
        let input = serde_json::to_string(&item).unwrap();
        let mut hasher = Sha256::new();
        hasher.update(input.as_bytes());
        let res= hasher.finalize();
        let vec_res = res.to_vec();

        Chain::hex_to_string(vec_res.as_slice())
    }

    pub fn hex_to_string(vec_res:&[u8])->String{
        let mut s =String::new();
        for b in vec_res{
            write!(&mut s,"{:x}",b).expect("Unable to write");
        }

        s
    }

}

