use std::collections::HashMap;
use std::io;

fn solver(n: u64, p: u64, q: u64, cache: &mut HashMap<u64, u64>) -> u64 {
    if n == 0 {
        return 1;
    }
    if cache.contains_key(&n) {
        return *cache.get(&n).unwrap();
    }
    let a_p = solver(n / p, p, q, cache);
    let a_q = solver(n / q, p, q, cache);
    cache.insert(n, a_p + a_q);
    *cache.get(&n).unwrap()
}

fn main() {
    let mut cache = HashMap::new();
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("error");

    let input: Vec<u64> = input
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();
    cache.insert(0, 1);
    println!("{}", solver(input[0], input[1], input[2], &mut cache));
}
