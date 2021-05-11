/*
 * Return the number (count) of vowels in the given string.
 * We will consider a,e,i,o,u as vowels. The input string will only consist
 * of lower case letters and/or spaces
 * */

// Python solution
// sample="return the number of vowels"
// len([_ for c in sample if c in "aeiou"])

/* Simple implementation */

fn simple_impl(sample: &str)-> u64 {
    let mut count:u64 = 0;
    for c in sample.chars() {
        if c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' {
            print!("{}", c);
            count += 1;
        }
    }
    println!("");
    count
}


fn main() {
    let sample = String::from("return the number of vowels");
    let vowels = simple_impl(&sample);
    println!("String {}:\nContains: {} vowels", sample, vowels);
}
