$fn=20;

$PLATE_THICKNESS = 1.6 - 0.1; // minus 3d printer tolerence


if (false)
    color("gray")
    rotate([180,180,180])
    translate([-45.9,129 ,-4.7])
    #import ("amc48k_PCBv2.stl");



 
difference()
{
 intersection()
 {  
     
     $CHOP_POINT=119+(19.02*5)+0.4;  // Half and half chop point
     // Small print section
//     rotate([0,0,3]) // rotate to create a diagonal split of the 2 halfs.
     {  
        translate([-100,-100,-10])
//        cube([119,192,20]); //1x4
//        cube([140,142,20]); //3x3
        //cube([900,900,20]);  // Everything
        
        //////////////////////////////
        // Half and half
        //////////////////////////////
        if(false){//6x4_left
            cube([$CHOP_POINT,192,20]); 
        }else{ //6x4_right
            translate([$CHOP_POINT,0,0])
            cube([$CHOP_POINT,192,20]); 
        }
    }
 
     
     union(){
         for ( row = [0:  19.02: 80] )
         {
             $ROW_LEN=232;
             color("green")
             translate([0,row,0])
             translate([-5+2.5,-4,-3])
             
             
             if (row>70)            // Top row is thicker
                cube([$ROW_LEN,3+5.7,3]);
             else if (row>10)
                cube([$ROW_LEN,3,3]);
             else{                  // Bottom row is thicker
                translate([0,-1,0])
                cube([$ROW_LEN,3+1,3]);
             }
         }
        

        
         
         //left side support
        
         union(){
            // Bottom left Support (Row 0)
            color("orange")
            translate([-21.5,-5,-3])
            cube([19,5,3+$PLATE_THICKNESS]);

            // Middle left Support (Row 1)
            color("orange")
            translate([-21.5,-5+(19.02*1)+1,-3])
            cube([19,3,3+$PLATE_THICKNESS]);

            // Middle left Support (Row 2)
            color("orange")
            translate([-21.5,-5+(19.02*2)+1+0,-3])
            cube([19,7+3,3+$PLATE_THICKNESS]);

            color("orange")
            translate([-21.5,-4,-3])
            cube([1.5,45,3+$PLATE_THICKNESS]);
        }



         
        for ( col = [0:  19.02: 240] )
         {
             
             translate([col,0,0])
             color("blue")
             translate([-2.54,-4,-3]){
                 if (col < 220){
                    cube([2,78,3]);
                 }else{
                    cube([2+2,78,3]); // might need extending a bit more
                 }                     
                 
                 
             }
         }
         
         
         if(true)    // The Plate is a cube minus the holes for the switches
         difference(){
             if(true) // Basic top layer
                 translate([-5+2.5,-5,0])
                 color("red")    
                 cube([232,86-0.3,$PLATE_THICKNESS]);
             else
                 translate([-5+2.5-18.5,-5,0])
                 color("re2")    
                 cube([235+18.5,86,$PLATE_THICKNESS]);
             
             
             
             linear_extrude(height=5, center=true, convexity= 10){
                 import("kbplate.svg");
             }
         }
     }    
 }
 // Remove bolt holes
 // Bolt Hole bottom left
 translate([-19.1,-2.4,-10])
 cylinder(h=20,d=2.5);

 // Bolt Hole Middle left
 translate([-19.1,-2.4,-10])
 translate([0.5,40.8,0])
 cylinder(h=20,d=2.5);

 // Bolt Hole Top left
 translate([-19.1,-2.4,-10])
 translate([20,80.8,0])
 cylinder(h=20,d=2.5);

 // Bolt Hole Top middle
 translate([-19.1,-2.4,-10])
 translate([131.8,80.9,0])
 cylinder(h=20,d=2.5);
 
 // Bolt Hole Bottom middle
 translate([-19.1,-2.4,-10])
 translate([131.8,0.0,0])
 cylinder(h=20,d=2.5);

 // Bolt Hole Bottom right
 translate([-19.1,-2.4,-10])
 translate([246.0,0.0,0])
 cylinder(h=20,d=2.5);
 
 // Bolt Hole middle right
 translate([-19.1,-2.4,-10])
 translate([246.0,38.0,0])
 cylinder(h=20,d=2.5);

 // Bolt Hole Top right
 translate([-19.1,-2.4,-10])
 translate([246.0,80.1,0])
 cylinder(h=20,d=2.5);
 
 // Horizonal join top
 translate([107.0-40,77.0-2,-1])
 rotate([0,90,0])
 #cylinder(h=80,d=2.5);
 
   // Horizonal join bottom
 translate([109.9-40,19-2.5,-0.1])
 rotate([0,90,0])
 #cylinder(h=80,d=2.5);
 
 
}



 
 
//#linear_extrude(height=5, center=true, convexity= 10){
//         import("kbplate_bot.svg");
//}
 
 
 if(false)
 translate([8,7,12])
{

	//1. steam
	color("brown"){
		//1.1. l-r tab is 1.35mm
		translate([0,0,-3.62/2])
			cube([1.35,4.5,3.62], center=true);
		//1.2. f-b tab is 1.15mm. it has a smal notch that i will ignore.
		translate([0,0,-3.62/2])
			cube([4.5,1.15,3.62], center=true);
		//1.3. base. it has a chamfered top that i will ignore.
		translate([0,0,-5.62])
			cube([7.2,5.56,4], center=true);
	}
	// 2. top
	color("grey"){
		difference(){
			// make a trapezoid with the general shape (volume?) of the top
			hull(){
				translate([0,0,-4]) //distance from top of switch... some i measured 3.9 others 4.2... so leaving at 4
					cube([9.87,10.62,0.1], center=true);
				translate([0,0,-4 -5.2]) // bottom has a measured 5.3... so move 5.2 and use the 0.1 bellow
					cube([14.58,14.58,0.1], center=true);
			}

		// and subtract:
		// the front led. NOTE: totally off... measured by eye. just for astetics
		// adding just so there is a visual cue of the direction
			translate([0,-4.7,-6])
				cylinder(r=3/2, h=6, center=true);
			translate([0,-5.5,-6])
				cube([8,4,5], center=true);
		// the four corners
			// TODO waste of time? this is all for looks, you shouldn't invade any of that space anyway...
		}
	}

	// 3. bottom
	color("green")
		// 3.1 main body volume
		hull(){
				translate([0,0,-4 -5.3]) //steam + top
					cube([13.98,13.98,0.1], center=true);
				translate([0,0,-4 -5.3 -2.2]) //steam + top + straigth part
					cube([13.98,13.98,0.1], center=true);
				translate([0,0,-4 -5.3 -5.5]) //steam + top + bottom (measured 5.5)
					cube([12.74,13.6,0.1], center=true);
		}
		// 3.2 tabs
		// note: only measured the lenght, if they are slightly off-center, this will be all wrong :)
		color("black")
		difference(){
			translate([0,0,-4 -5.3 -0.82/2]) //steam + top
				cube([15.64,15.64,0.82], center=true);
			translate([0,0,-4 -5.3 -0.82/2  ]) // front-back cut
				cube([5.64,20,0.82 +2], center=true);
			translate([0,0,-4 -5.3 -0.82/2  ]) //side cut
				cube([20,11.64,0.82 +2], center=true);
		}

		// 3.3 tab (plate snap on). to use this mechanically, you have to take into account the bending (as it will move the bottom part slightly up...) just for gross reference here for now
		color("white"){
			// 3.3.1 top
			translate([0,0,-4 -5.3 -0.82/2  ]) // front-back cut
				cube([1.82,16.33,0.82], center=true);
			// 3.3.2 bottom
			difference(){
				hull(){
					translate([0,0,-4 -5.3 -0.82/2 -1.76  ]) // front-back cut
						cube([3.65,14,0.1], center=true);
					translate([0,0,-4 -5.3 -0.82/2 -2.2  ]) // front-back cut
						cube([3.65,14.74,0.1], center=true);
					translate([0,0,-4 -5.3 -0.82/2 -2.89  ]) // front-back cut
						cube([3.65,14,0.1], center=true);
				}
				translate([0,0,-4 -5.3 -0.82/2 -1.76   ]) // front-back cut
					cube([2.2,20,4], center=true);

			}
		}

		// 4. bottom guides
		// again, i'm assuming everything is centered...
		color("darkGreen"){
			// 4.1 cylinder
			translate([0,0,-4 -5.3 -5.5 -2/2]) //steam + top + bottom (measured 5.5)
				cylinder(r=3.85/2, h=2, center=true);
			translate([0,0,-4 -5.3 -5.5 -2 -1/2]) //steam + top + bottom (measured 5.5)
				cylinder(r2=3.85/2, r=2.8/2, h=1, center=true);
			// 4.2 PCB pins
			translate([4.95,0,-4 -5.3 -5.5 -2/2]) //steam + top + bottom (measured 5.5)
				cylinder(r=1.6/2, h=2, center=true);
			translate([4.95,0,-4 -5.3 -5.5 -2 -1/2]) //steam + top + bottom (measured 5.5)
				cylinder(r2=1.6/2, r=1/2, h=1, center=true);
			translate([-4.95,0,-4 -5.3 -5.5 -2/2]) //steam + top + bottom (measured 5.5)
				cylinder(r=1.6/2, h=2, center=true);
			translate([-4.95,0,-4 -5.3 -5.5 -2 -1/2]) //steam + top + bottom (measured 5.5)
				cylinder(r2=1.6/2, r=1/2, h=1, center=true);
		}

		// 5. pins
		color("orange"){
			translate([-3.77,2.7,-4 -5.3 -5.5 -3.1/2]) //steam + top + bottom (measured 5.5)
				cube([.86, 0.2,3.1], center=true);
			translate([2.7,5.2,-4 -5.3 -5.5 -3.1/2]) //steam + top + bottom (measured 5.5)
				cube([.86, 0.2,3.1], center=true);
		}

}

 
 /*
 }
 */
 