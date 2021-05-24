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

fn other_impl(sample: &str) -> u64 {
    let mut count:u64=0;
    for c in sample.chars() {
        match c {
            'a'|'e'|'i'|'o'|'u' => count+=1,
            _ => (),
        }
    }
    count
}


fn show_index(sample: &str) -> u64 {
    let mut count:u64 = 0;
    for (i,c) in sample.chars().enumerate() {
        match c {
            'a'|'e'|'i'|'o'|'u' => {
                println!("{} index {}", c,i);
                count +=1;
            },
            _ => (),
        }
    }
    count
}


fn main() {
    let sample = String::from("return the number of vowels");
    let vowels = simple_impl(&sample);
    let other_vowels = other_impl(&sample);
    let _ = show_index(&sample);
    println!("String {}:\nContains: {} vowels", sample, vowels);

//    let count = sample.into_bytes().iter().filter(|c| c == 'u');
    println!("String {}:\nContains: {} vowels", sample, vowels);
    println!("String {}:\nContains: {} other vowels", sample, other_vowels);

}
