use std::io::{self, Read, Write};

// ---- Type Alias (like the `using ll = long long;`) ----------------------
#[allow(dead_code)]
type Ll = i64; // entero de 64 bits  (long long)
#[allow(dead_code)]
type Ull = u64; // sin signo de 64 bits
// Para casos extremos existe i128 / u128 nativos (no hay en C++ estandar).

// ---- Scanner: lee tokens separados por espacios/saltos de linea ------------
// Lee TODO stdin de golpe (rapido) y lo va parseando token a token.
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
    // lee n valores en un Vec<T>
    fn vec<T: std::str::FromStr>(&mut self, n: usize) -> Vec<T> {
        (0..n).map(|_| self.next()).collect()
    }
}

fn main() {
    // Entrada completa -> String -> Scanner
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut sc = Scanner::new(&input);

    // Salida BUFERIZADA (sin esto, imprimir miles de lineas es lentisimo).
    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());

    // -------------------- TU SOLUCION AQUI --------------------
    let n: usize = sc.next();
    let a: Vec<Ll> = sc.vec(n);
    let suma: Ll = a.iter().sum();
    writeln!(out, "{}", suma).unwrap();
    // ----------------------------------------------------------
}
