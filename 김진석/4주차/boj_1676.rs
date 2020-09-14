use io::{Read, Write};
use std::io;

fn divide(mut dividend: i32, divisor: i32) -> i32 {
    let mut quotient = 0;
    while dividend % divisor == 0 {
        quotient += 1;
        dividend /= divisor;
    }
    quotient
}
fn main() {
    let mut stdin = std::io::BufReader::new(std::io::stdin());
    let mut stdout = std::io::BufWriter::new(std::io::stdout());
    let mut input = String::new();
    stdin.read_to_string(&mut input).unwrap();
    let input: i32 = input.trim().parse().unwrap();
    if input == 0 {
        writeln!(stdout, "{}", 0).unwrap();
        return;
    }
    let mut count_twos = 0;
    let mut count_fives = 0;
    for n in 1..input + 1 {
        count_fives += divide(n, 5);
        count_twos += divide(n, 2);
    }
    if count_fives > count_twos {
        writeln!(stdout, "{}", count_fives - (count_fives - count_twos)).unwrap();
    } else {
        writeln!(stdout, "{}", count_twos - (count_twos - count_fives)).unwrap();
    }
}
