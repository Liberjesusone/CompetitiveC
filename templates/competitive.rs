use std::io::{self, Read, Write};

// ---- Type Alias (like the `using ll = long long;`) ----------------------
#[allow(dead_code)]
type Ll = i64; // a 64 bits integer (long long)
#[allow(dead_code)]
type Ull = u64; // unsigned 64 bits integer
// For extrem cases there is i128 / u128 natives (there isn't in C++ standard).

// ---- Scanner: Reads tokes separated for spaces/line jumps ------------
// Reads EVERYTHING stdin quickly (fast) and parses it token by token
struct Scanner {
    buf: std::vec::IntoIter<String>,
}
impl Scanner {
    fn new(s: &str) -> Self {
        Scanner {
            buf: s
                .split_ascii_whitespace()
                .map(String::from)
                .collect::<Vec<_>>()
                .into_iter(),
        }
    }
    // next::<i64>(), next::<usize>(), next::<f64>(), next::<String>() ...
    fn next<T: std::str::FromStr>(&mut self) -> T {
        self.buf.next().unwrap().parse().ok().expect("parse error")
    }
    // Reads n values un a Vec<T>
    fn vec<T: std::str::FromStr>(&mut self, n: usize) -> Vec<T> {
        (0..n).map(|_| self.next()).collect()
    }
}

fn main() {
    // Complete entry -> String -> Scanner
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut sc = Scanner::new(&input);

    // BUFERED output (without this, printing thousands of lines is very slow).
    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());

    // -------------------- The solution here --------------------
    let n: usize = sc.next();
    let a: Vec<Ll> = sc.vec(n);
    let suma: Ll = a.iter().sum();
    writeln!(out, "{}", suma).unwrap();
    // ----------------------------------------------------------
}
