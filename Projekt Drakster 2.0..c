#pragma config(Sensor, S4,     ,               sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          motor_L,       tmotorEV3_Large, PIDControl, reversed, encoder)
#pragma config(Motor,  motorC,          motor_R,       tmotorEV3_Large, PIDControl, reversed, encoder)
#pragma config(Motor,  motorD,          motor_Arm,     tmotorEV3_Medium, PIDControl, reversed, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int IR = 100;
int otacky_vpravo90st = 283;
int otacky_jizda = 2;
task main()

{
Start_of_code:	// smyeka od konce programu

resetMotorEncoder(motor_R);
resetMotorEncoder(motor_L);
resetMotorEncoder(motor_Arm);
displayBigTextLine(5, "START");
displayBigTextLine(3, "A %i", IR);
sleep(1000);
setMotorSpeed(0, 50); // motor: motorA - 0, ...,  motorD - 3 ; rychlost: -100 .. 100
setMotorSpeed(2, 50);
sleep(200);
displayBigTextLine(3, "B %i", IR);
while ( IR > 20) // priblizuje se ke zdi
	{
	IR  = getUSDistance(3); // IR = getIRDistance(3);
	displayBigTextLine(3, "C %i", IR);
	sleep(100);
	}
IR = getUSDistance(3);
displayBigTextLine(3, "D %i", IR);
// stopMultipleMotors(motor_L , motor_R); // stuj pred zdi - nefunguje proe??
setMotorSpeed(motor_R, 0); // motor: motorA - 0, ...,  motorD - 3 ; rychlost: -100 .. 100
setMotorSpeed(motor_L, 0);

sleep(1000);
displayBigTextLine(3, "D2 %i", IR);
moveMotorTarget(motor_L, otacky_vpravo90st, 50); // ktery motor, stupne, rychlost - mel by tocit vpravo o 90 stupnu
moveMotorTarget(motor_R, otacky_vpravo90st, -50); // ktery motor, stupne, rychlost - mel by tocit vpravo o 90 stupnu
waitUntilMotorStop(motor_L);  // kdyz tam tohle nebude, tak se program skonci driv, nez se motor vubec rozjede
waitUntilMotorStop(motor_R);
IR = getUSDistance(3);
displayBigTextLine(3, "E %i", IR);
setMotorSpeed(0, 50); // motor: motorA - 0, ...,  motorD - 3 ; rychlost: -100 .. 100
setMotorSpeed(2, 50);
sleep(200);
while ( IR > 20) // priblizuje se ke druhe zdi
	{
	IR = getUSDistance(3);
	displayBigTextLine(3, "F %i", IR);
	sleep(100);
	}

setMotorSpeed(motor_R, 0); // motor: motorA - 0, ...,  motorD - 3 ; rychlost: -100 .. 100
setMotorSpeed(motor_L, 0);
sleep(900);
displayBigTextLine(3, "G %i", IR);
moveMotorTarget(motor_L, otacky_vpravo90st, 50); // ktery motor, stupne, rychlost - mel by tocit vpravo o 90 stupnu
moveMotorTarget(motor_R, otacky_vpravo90st, -50); // ktery motor, stupne, rychlost - mel by tocit vpravo o 90 stupnu
waitUntilMotorStop(motor_L);  // kdyz tam tohle nebude, tak se program skonci driv, nez se motor vubec rozjede
waitUntilMotorStop(motor_R);

moveMotorTarget(motor_L, 360*otacky_jizda, 50); // znovu se rozjede a zastavi
moveMotorTarget(motor_R, 360*otacky_jizda, 50);
waitUntilMotorStop(motor_L);
waitUntilMotorStop(motor_R);

setLEDColor(ledGreen); // je spokojeny :-)

goto Start_of_code;
}
