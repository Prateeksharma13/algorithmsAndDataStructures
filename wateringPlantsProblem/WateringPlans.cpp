#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

/*** Complete this program. ***/

int main() {
	const int UNITS_PER_CAN = 3;
	const string INPUT_FILE_NAME = "counts.txt";
	int plant_count;

	ifstream input;
	input.open(INPUT_FILE_NAME);
	if (input.fail()) {
		cout << "Failed to open " << INPUT_FILE_NAME << endl;
		return -1;
	}

	// Loop once for each number of plants read from the input file.
	// Stop when the number of plants is 0 or less.
	// During each loop, simulate Plan Near and Plan Far.
	while (input >> plant_count) {

		//Ignoring a corner case

		if (plant_count == 0) {
			continue;
		}

		//Total cycles to run in the for life
		int total_cycles = (plant_count / UNITS_PER_CAN);

		//Exclusively to compute near values

		int cumulitive_steps_near = 0;

		int cumulitive_steps_near_units = 0;

		//Total cycles in case there are extra plants in the last cycle

		if (plant_count % UNITS_PER_CAN) {
			total_cycles += 1;
		}

		//left water is to track water at the last step

		int left_water = 0;

		cout << endl;
		cout << "==========================" << endl;
		cout << " Plan Near with " << plant_count << " plants" << endl;
		cout << "==========================" << endl;
		cout << endl;
		cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
		cout << "---------  ----------  ----------  ---------------" << endl;

		//This is the for loop to compute near data
		for (int current_cycle = 0; current_cycle < total_cycles;
				current_cycle++) {
			int step_units_till_last_plant = current_cycle * 9;
			int steps_till_last_plant = current_cycle * 3;
			cumulitive_steps_near += steps_till_last_plant;
			cumulitive_steps_near_units += step_units_till_last_plant;
			int step_units_this_cycle = 0;
			int steps_this_cycle = 0;

			//Special case for the last cycle

			if (current_cycle == total_cycles - 1) {
				int last_cycle_number = plant_count % 3;
				if (!last_cycle_number) {
					last_cycle_number = 3;
				}
				switch (plant_count % 3) {
				case 1:
					step_units_this_cycle = 3;
					steps_this_cycle = 1;
					left_water = 2;
					break;
				case 2:
					step_units_this_cycle = 5;
					steps_this_cycle = 2;
					left_water = 1;
					break;
				case 0:
					step_units_this_cycle = 6;
					steps_this_cycle = 3;
					left_water = 0;
					break;
				}

				//For other cycles

				for (int i = 0; i < last_cycle_number; i++) {
					cumulitive_steps_near += 1;
					cumulitive_steps_near_units += (3 - i);
					cout << "Plant  " << steps_till_last_plant + i + 1
							<< std::setw(9) << cumulitive_steps_near
							<< std::setw(11) << 3 - i << std::setw(15)
							<< cumulitive_steps_near_units << endl;
				}
				cumulitive_steps_near += ((current_cycle) * 3)
						+ last_cycle_number;
			} else {
				for (int i = 0; i < 3; i++) {
					cumulitive_steps_near += 1;
					cumulitive_steps_near_units += (3 - i);
					cout << "Plant  " << steps_till_last_plant + i + 1
							<< std::setw(9) << cumulitive_steps_near
							<< std::setw(11) << 3 - i << std::setw(15)
							<< cumulitive_steps_near_units << endl;
				}
				cumulitive_steps_near += (current_cycle + 1) * 3;
			}

			cout << "FAUCET " << std::setw(10) << cumulitive_steps_near
					<< std::setw(11) << left_water << std::setw(15)
					<< cumulitive_steps_near_units + (plant_count * left_water)
					<< endl;
		}
		cout << endl;
		cumulitive_steps_near_units += (plant_count * left_water);
		cout << "Plan Near: Total steps = " << cumulitive_steps_near
				<< ", total step-units = " << cumulitive_steps_near_units;

		cout << endl;
		cout << endl;
		cout << "=========================" << endl;
		cout << " Plan Far with " << plant_count << " plants" << endl;
		cout << "=========================" << endl;
		cout << endl;
		cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
		cout << "---------  ----------  ----------  ---------------" << endl;

		//Variable for computing the far values 

		int cumulitive_steps_far = 0;
		int cumulitive_steps_units_far = 0;
		left_water = 0;

		//For loop for calculating the far values

		for (int current_cycle = 0; current_cycle < total_cycles;
				current_cycle++) {
			int starting_plant = plant_count - (current_cycle * 3);
			cumulitive_steps_far += starting_plant;
			cumulitive_steps_units_far += starting_plant * 3;
			if (current_cycle == total_cycles - 1) {
				int plants_left = starting_plant;
				cout << "Plant  " << starting_plant << std::setw(9)
						<< cumulitive_steps_far << std::setw(11) << 3
						<< std::setw(15) << cumulitive_steps_units_far << endl;

				for (int last_iteration = 1; last_iteration < plants_left;
						last_iteration++) {
					cumulitive_steps_far += 1;
					starting_plant--;
					cumulitive_steps_units_far += (3 - last_iteration);
					cout << "Plant  " << starting_plant << std::setw(9)
							<< cumulitive_steps_far << std::setw(11)
							<< 3 - last_iteration << std::setw(15)
							<< cumulitive_steps_units_far << endl;

				}
				cumulitive_steps_far += 1;
				left_water = 3 - plants_left;
				cumulitive_steps_units_far += left_water;
			} else {
				cout << "Plant  " << starting_plant << std::setw(9)
						<< cumulitive_steps_far << std::setw(11) << 3
						<< std::setw(15) << cumulitive_steps_units_far << endl;
				for (int far_iteration = 1; far_iteration < 3;
						far_iteration++) {
					cumulitive_steps_far += 1;
					cumulitive_steps_units_far += (3 - far_iteration);
					cout << "Plant  " << starting_plant - far_iteration
							<< std::setw(9) << cumulitive_steps_far
							<< std::setw(11) << 3 - far_iteration
							<< std::setw(15) << cumulitive_steps_units_far
							<< endl;
				}
				int plants_left = plant_count - ((current_cycle + 1) * 3) + 1;
				cumulitive_steps_far += plants_left;
			}

			cout << "FAUCET " << std::setw(10) << cumulitive_steps_far
					<< std::setw(11) << left_water << std::setw(15)
					<< cumulitive_steps_units_far << endl;
		}

		cout << endl << "Plan Far: Total steps = " << cumulitive_steps_far
				<< ", total step-units = " << cumulitive_steps_units_far
				<< endl;

		// Logic to find which method is better

		if (cumulitive_steps_units_far > cumulitive_steps_near_units) {
			int difference = cumulitive_steps_units_far
					- cumulitive_steps_near_units;
			cout << endl;
			cout << "*** With " << plant_count
					<< " plants, Plan Near is better with " << difference
					<< " fewer step-units.";
			cout << endl;
		} else {
			int difference = cumulitive_steps_near_units
					- cumulitive_steps_units_far;
			cout << endl;
			cout << "*** With " << plant_count
					<< " plants, Plan Far is better with " << difference
					<< " fewer step-units.";
			cout << endl;

		}

	}

	return 0;
}
