use io::{Read, Write};
use std::io;

fn solver(n: usize, y: usize, x: usize, cells: &Vec<Vec<char>>) -> String {
    if n == 1 {
        return cells[y][x].to_string();
    }
    let upper_left = solver(n / 2, y, x, cells);
    let upper_right = solver(n / 2, y, x + n / 2, cells);
    let downer_left = solver(n / 2, y + n / 2, x, cells);
    let downer_right = solver(n / 2, y + n / 2, x + n / 2, cells);
    if upper_left == upper_right && upper_right == downer_left && downer_left == downer_right {
        if upper_left == "1" || upper_left == "0" {
            return upper_left;
        }
    }
    let output = format!(
        "({}{}{}{})",
        upper_left, upper_right, downer_left, downer_right
    );
    output
}
fn main() {
    let mut stdin = std::io::BufReader::new(std::io::stdin());
    let mut stdout = std::io::BufWriter::new(std::io::stdout());
    let mut input = String::new();
    stdin.read_to_string(&mut input).unwrap();
    let n: usize = input.lines().next().unwrap().parse().unwrap();
    let input: Vec<Vec<char>> = input.lines().skip(1).map(|x| x.chars().collect()).collect();
    writeln!(stdout, "{}", solver(n, 0, 0, &input)).unwrap();
}
