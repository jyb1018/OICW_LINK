use io::{BufRead, Write};
use std::io;

fn find(element: i32, parents: &mut Vec<i32>) -> i32 {
    if element == parents[element as usize] {
        return element;
    }
    let p = find(parents[element as usize], parents);
    parents[element as usize] = p;
    p
}

fn union(element_a: i32, element_b: i32, parents: &mut Vec<i32>) {
    let parents_a = find(element_a, parents) as usize;
    let parents_b = find(element_b, parents) as usize;
    if parents_a == parents_b {
        return;
    }
    parents[parents_a] = parents_b as i32;
}

fn main() {
    let stdin = io::stdin();
    let mut stdin = stdin.lock();
    let mut input = String::new();
    stdin.read_line(&mut input).unwrap();
    let mut input = input.trim().split_whitespace();
    let n: i32 = input.next().unwrap().parse().unwrap();
    let m: i32 = input.next().unwrap().parse().unwrap();
    let mut parents: Vec<i32> = (0..n + 2).collect();

    let stdout = io::stdout();
    let mut out_stream = io::BufWriter::new(stdout.lock());
    for _ in 0..m {
        let mut input = String::new();
        stdin.read_line(&mut input).unwrap();
        let input: Vec<i32> = input
            .trim()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        if input[0] == 0 {
            union(input[1], input[2], &mut parents);
        } else {
            let a = find(input[1], &mut parents);
            let b = find(input[2], &mut parents);
            if a != b {
                writeln!(out_stream, "{}", "NO").unwrap();
            } else {
                writeln!(out_stream, "{}", "YES").unwrap();
            }
        }
    }
}
