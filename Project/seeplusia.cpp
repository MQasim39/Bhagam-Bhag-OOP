#include "seeplusia.hpp"
#include "mover.hpp"

int applesLeft = 20, nCrystalsFound = 0, crystalA = 1, crystalB = 1, crystalC = 1, crystalD = 1;
string gameState = "Running";

string currentState = "Enchanted Forest";

void apple_status(int subtractor){ // this function will add or subtract apples and store their value 
	applesLeft -= subtractor; //calling this function will do the necessary increment/decrement of apples
	if (applesLeft <= 0){
		gameState = "Lost";
		cout <<"You consumed all apples" << endl;
	}
}
void crystal_status(int adder){ // calling this function will add crystals wherever they are present
	nCrystalsFound += adder;
}

void final_moveA(int nCrystalsFound){ // this function will check and control the final move from the bridge of death to the wizard's castle
	if (nCrystalsFound == 4 && applesLeft >= 5 ){ //here the apple and crystal counts are checked
		currentState = "Wizard's Castle";
		moveWest();
		gameState = "Won";
		cout << "You are in Wizard's Castle" << endl;
		apple_status(5);
	}
	else if (nCrystalsFound < 4 && applesLeft < 5){
		cout << "You are not allowed to enter" << endl;
		gameState = "Running";
	}
}
void final_moveB(int nCrystalsFound){ //will check and control the final move from einstein's tunnel to wizard's castle
	if (nCrystalsFound >= 3 && applesLeft >= 10 ){ //checks crystal/apple count as required in question
		currentState = "Wizard's Castle";
		moveNorth();
		moveNorth();
		cout << "You are in Wizard's Castle" << endl;
		gameState = "Won";
		apple_status(10);
	}
	else if (nCrystalsFound < 3 && applesLeft < 10){
		cout << "You are not allowed to enter" << endl;
		gameState = "Running";
	}
}
void east(){//When Right Arrow is pressed this function will have all possible eastward if else if conditions from all places
	if (currentState == "Enchanted Forest" && applesLeft>=1){
		currentState = "Sands of Quick";
		gameState = "Lost"; // game goes into lost state if we arrive at sands of quick 
		moveEast(); // no invalid conditions have been made for sands of quick
		cout<<"You sunk into sand" << endl;
		apple_status(1);
	}
	else if (currentState == "Wampire Cove" && applesLeft>=1){
		currentState = "Marsh of Undead";
		gameState = "Running";
		moveEast();
		cout<<"You are among the Undead" << endl;
		apple_status(1);
		crystal_status(crystalA);
		crystalA -= 1; // crystal variable decrements here and this was initialized at 1 so this prevents re adding of crystals upon revisits
	}
	else if (currentState == "Marsh of Undead" || currentState == "Apples Orchard" || currentState == "Bridge of Death"){ 
		gameState = "Running";
		cout<<"You made an invalid move" << endl; //all impossible eastward invalid moves are lumped together using OR operator in if condition
		apple_status(1);
	}
	else if (currentState == "Elvin Waterfall" && applesLeft>=2 ){
		currentState = "Werewolf Hill";
		gameState = "Running";
		moveEast();
		cout<<"You are in Werewolf Hill" << endl;
		apple_status(2);
	}
	else if (currentState == "Swamps of Despair" && applesLeft>=1){
		currentState = "Wampire Cove";
		gameState = "Running";
		moveEast();
		cout<<"You are in Wampire Cove" << endl;
		apple_status(1);
	}
	else if (currentState == "Einstein Tunnel" && applesLeft>2){
		currentState = "Elvin Waterfall";
		gameState = "Running";
		moveEast();
		cout<<"You are in Wampire Cove" << endl;
		apple_status(2);
	}
	}
void west(){//When Left Arrow is pressed
	if (currentState == "Enchanted Forest" || currentState == "Swamps of Despair" || currentState == "Einstein Tunnel"){
		gameState = "Running";
		cout<<"You made an invalid move" << endl;
		apple_status(1);
	}
	else if (currentState == "Wampire Cove" && applesLeft>=1){
		currentState = "Swamps of Despair";
		gameState = "Running";
		moveWest();
		cout<<"You are in Despair" << endl;
		apple_status(1);
		crystal_status(crystalB);
		crystalB -= 1;
	}	
	else if (currentState == "Marsh of Undead" && applesLeft>=1){
		currentState = "Wampire Cove";
		gameState = "Running";
		moveWest();
		cout<<"You are among the Undead" << endl;
		apple_status(1);
	}
	else if (currentState == "Apples Orchard" && applesLeft>=1){
		currentState = "Werewolf Hill";
		gameState = "Running";
		moveWest();
		cout<<"You are among Werewolves" << endl;
		apple_status(1);
		crystal_status(crystalC);
		crystalC -= 1;
	}
	else if (currentState == "Werewolf Hill" && applesLeft>=2){
		currentState = "Elvin Waterfall";
		gameState = "Running";
		moveWest();
		cout<<"You are in Elvin Waterfall" << endl;
		apple_status(2);

	}
	else if (currentState == "Elvin Waterfall" && applesLeft>=1){
		currentState = "Einstein Tunnel";
		gameState = "Running";
		moveWest();
		cout<<"You are in Einstein Tunnel" << endl;
		apple_status(1);
		crystal_status(crystalD);
		crystalD -= 1;
	}
	else if (currentState == "Bridge of Death"){
		final_moveA(nCrystalsFound);
	}
	}
void north(){
	if (currentState == "Enchanted Forest" || currentState == "Marsh of Undead" || currentState == "Apples Orchard" || currentState == "Elvin Waterfall" || currentState == "Bridge of Death"){
		gameState = "Running";
		cout<<"You made an invalid move" << endl;
		apple_status(1);
	}

	else if (currentState == "Wampire Cove" && applesLeft>=3){
		currentState = "Enchanted Forest";
		gameState = "Running";
		moveNorth();
		cout<<"You are in Wampire Cove" << endl;
		apple_status(3);
	}
	else if (currentState == "Werewolf Hill" && applesLeft>=3){
		currentState = "Wampire Cove";
		gameState = "Running";
		moveNorth();
		cout<<"You are in Wampire Cove" << endl;
		apple_status(3);
	}
	else if (currentState == "Swamps of Despair" && applesLeft>1){
		currentState = "Bridge of Death";
		gameState = "Running";
		moveNorth();
		cout<<"You are on the Bridge of Death" << endl;
		apple_status(1);
	}
	else if (currentState == "Einstein Tunnel"){
		final_moveB(nCrystalsFound);
	}
}
void south(){
	if (currentState == "Enchanted Forest" && applesLeft>=3){
		moveSouth();  // Call this function only if warrior needs to be moved	
		cout<<"Provide South move implementation" << endl;		 
		currentState = "Wampire Cove";
		gameState = "Running";
		apple_status(3);
	}		
	else if (currentState == "Wampire Cove" && applesLeft>=3){
		currentState = "Werewolf Hill";
		gameState = "Running";
		moveSouth();
		cout<<"You are in Werewolf Hill" << endl;
		apple_status(3);
	}
	else if (currentState == "Marsh of Undead" && applesLeft>=1 ){
		currentState = "Apples Orchard";
		gameState = "Running";
		moveSouth();
		cout<<"An apple a day keeps troubles away" << endl;
		apple_status(-5);
	}
	else if (currentState == "Apples Orchard" || currentState == "Werewolf Hill" || currentState == "Elvin Waterfall" || currentState == "Einstein Tunnel" || currentState == "Swamps of Despair" || currentState == "Bridge of Death"){
		gameState = "Running";
		cout<<"You made an invalid move" << endl;
		apple_status(1);
	}
}
void makeMove(string direction){
	//condition
	if (gameState == "Running"){
		if (direction == "East"){ //When Right Arrow is pressed
	 		east();
		}
		else if (direction == "West"){ //When Left Arrow is pressed
			west();
		}
		else if (direction == "North"){ //When Up Arrow is pressed
			north();
		}
		else if (direction == "South"){//When Down Arrow is pressed	
			south();
		}
	}
}

