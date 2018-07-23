macro_rules! readline {
    ($ty: ty) => {{
        let mut line = String::new();
        ::std::io::stdin().read_line(&mut line).unwrap();
        line.trim().parse::<$ty>().unwrap()
    }};
    ($($ty: ty),+) => ({
        let mut line = String::new();
        ::std::io::stdin().read_line(&mut line).unwrap();
        let mut iter = line.split_whitespace();
        ($(iter.next().unwrap().parse::<$ty>().unwrap(),)+)
    });
}

fn main() {
    let mut m = [0; 10];
    for _ in 0 .. readline!(i32) {
        let mut n = readline!(i32);
        let mut len = 0;
        while n != 0 {
            m[len] = n % 3;
            n /= 3;
            if m[len] == 2 {
                n += 1;
            }
            len += 1;
        }
        for i in (0 .. len).rev() {
            if m[i] == 0 {
                print!("0");
            } else {
                print!("{}", if m[i] == 1 { '+' } else { '-' })
            }
        }
        println!("");
    }
}
