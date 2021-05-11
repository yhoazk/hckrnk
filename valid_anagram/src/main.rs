/*
 * Given two strings s and t return true if t is an anagram of s
 * and false otherwise
 * */
use itertools::Itertools;

fn is_anagram(s: &String, t: &String)-> bool {
    let ss = s.chars().sorted().collect::<String>();
    let tt = t.chars().sorted().collect::<String>();
    tt == ss
}

// solution as a lambda

fn main() {
    let samples = vec![
        ("test", "tset"),
        ("rat", "rrat"),
        ("rat", "cat"),
        ("anagram", "nagaram")];

    for (a,b) in samples {
        print!("a: {} b: {} -> ", a,b);
        if is_anagram(a.to_string(), b.to_string()) {
            println!("An anagram");
        } else {
            println!("Not Anagram");
        }
    }
    let orig = "salado".to_string();
    // let orig_sort = String::from(orig.chars().sorted());
    //let orig_sort = orig.chars().sorted().rev().collect::<String>();
    let orig_sort = orig.chars().sorted().collect::<String>();
    println!("Orig: {} Sorted: {}", orig, orig_sort);
}
