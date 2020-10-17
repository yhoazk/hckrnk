use rand::prelude::*;
use std::env;
use plotters::prelude::*;
/* The question is:

    Given a random generator with a normal distribution
    calculate the value of PI

    What needs to be done is remember what how to calculate
    the area of a circle PI*r**2, then the area of a square
    where the circle will be, which we can make L=2

    Then the ratio between the two: (PIr^2) / 2L
    In order to get the area of this, calculate the number
    points that are inside the circle and the total of points

    PIr^2/2L = pts_circle / pts_total

    As r = 1 and L=2

    PI/2*2 = pts_circle / pts_total

    PI = 4(pts_circle / pts_total)
This could also be done for only 1/4 of the unitary circle   
*/



fn main() -> Result<(), Box<dyn std::error::Error>>{
    println!("Hello, world!");
    let args: Vec<String> = env::args().collect();

    let pt_cnt_str = &args[1];
    let pt_cnt = pt_cnt_str.parse().unwrap();
    let mut rnd = rand::thread_rng(); // which kind of distribution is this?

    // Plot part
    let mut plot_backend = BitMapBackend::new("plotter_data.png", (200,200));
    plot_backend.draw_circle((100,100), 100, &BLUE, false)?;
    let mut pt_inside:i32 = 0;
    for _ in 0..pt_cnt {
        let mut y : f64 = rnd.gen();
        let mut x : f64 = rnd.gen();
        x = x * 200f64;
        y = y * 200f64;

        // check if the point falls inthe circle or not
        // if it's inside the circle, for the case in the origin
        // r < sqrt(x*x + y*y)
        // for our graph representation we need to add the offset
        // This is the distance between the center and the curve of the circle
        // sqrt((x-offset_y)^2 + (y-offset_y)^2)
        // For a point to be inside of the circle, this has to be less than r
        // this could be simplified when we dont care of the image
        let circunscript : bool = ((x-100f64).powf(2.0) + (y-100f64).powf(2.0)).sqrt() < 100f64;
        //let &mut color = RED;
        let x = x as i32;
        let y = y as i32;
        if circunscript {
          //  color = GREEN;
            pt_inside +=1;
            plot_backend.draw_circle((x,y), 2, &GREEN, true)?;
        } else {
            plot_backend.draw_circle((x,y), 2, &RED, true)?;
        }
    }
    let aprox_pi = 4.0_f64 * (pt_inside as f64 / pt_cnt as f64);
    println!("Inside: {0} Total: {1} = 4({0}/{1}) = {2}", pt_inside, pt_cnt, aprox_pi);
    Ok(())
}
