use std::{collections::{HashMap, HashSet}, io::{self, Read, Write}};

struct Scanner { buf: std::vec::IntoIter<String> }
impl Scanner
{
    fn new(s: &str) -> Self { Scanner { buf: s.split_ascii_whitespace().map(String::from).collect::<Vec<_>>().into_iter() } }
    fn next<T: std::str::FromStr>(&mut self) -> T { self.buf.next().unwrap().parse().ok().expect("parse") }
    #[allow(dead_code)] fn vec<T: std::str::FromStr>(&mut self, n: usize) -> Vec<T> { (0..n).map(|_| self.next()).collect() }
}

/// # Time limit: 1.00 s
/// # Memory limit: 512 MB
/// 
/// Given a string, your task is to reorder its letters in such a way that it becomes a
/// palindrome (i.e., it reads the same forwards and backwards).
/// 
/// # Input
/// The only input line has a string of length n consisting of characters A–Z.
/// 
/// # Output
/// Print a palindrome consisting of the characters of the original string. You may print
/// any valid solution. If there are no solutions, print "NO SOLUTION".
/// 
/// # Constraints
/// 
/// 1 <= n <= 10^6
/// 
/// # Example
/// ## Input:
/// AAAACACBA
/// 
/// ## Output:
/// AACABACAA 
fn main()
{
    let mut input = String::new();                // we create the input string

    io::stdin().read_to_string(&mut input).unwrap(); // we pass it to the reader in a mutable referece 
    
    let mut sc = Scanner::new(&input);          // we create the scanner to analize all the data and separate it into strings

    let stdout = io::stdout();                   // we create the buffered output to be fast
    let mut out = io::BufWriter::new(stdout.lock());

    let word= sc.next::<String>();               // The vec of chars from the word 

    let mut map: HashMap<char, u64> = HashMap::new();
    let mut set: HashSet<char> = HashSet::new();
    let mut half_string = String::from("");
    for letter in word.chars()
    {
        if map.contains_key(&letter) && map[&letter] % 2 != 0 { half_string.push(letter); }

        *map.entry(letter).or_insert(0) += 1;   

        if map[&letter] % 2 != 0 { set.insert(letter); }
        else { set.remove(&letter); }
    }
    if set.len() <= 1
    {
        let mut result = half_string.clone();                         // first half
        if let Some(&mid) = set.iter().next() { result.push(mid); } // middle char if there's one odd 
        result.extend(half_string.chars().rev());                       // second half in reverse
        writeln!(out, "{result}").unwrap();
    }
    else { writeln!(out, "NO SOLUTION").unwrap(); }
}