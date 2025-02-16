#include "WorldBoundaries.h"

#include <iostream>

using namespace std;

bool clipCoordinates(float& x, float& y, bool& climbing, bool& should_fall, float& next_floor_y, bool& l_lives, bool& crawling, bool door, bool& jumped)
{

	bool clip = false;
	should_fall = false;
	climbing = false;
	l_lives = false;
	crawling = false;
	jumped = false;


	//
	// Floor 1:
	//
	if (y < 28.5f) {
		should_fall = true;
		next_floor_y = 28.5f;
	}

	//Floor 2:
	if (x >= 112 && x < 204 && y >= 60 && y < 76.5f) {
		should_fall = true;
		next_floor_y = 76.5f;
	}
	if (x >= 204 && x <= 271 && y >= 63 && y < 81.5f) {
		should_fall = true;
		next_floor_y = 81.5f;
	}
	if (x >= 58 && x < 102 && y >= 71 && y < 88.7f) {
		should_fall = true;
		next_floor_y = 88.7f;
	}
	if (x >= 46 && x < 58 && y >= 71 && y < 190) {
		should_fall = true;
		next_floor_y = 190;
	}
	if (x >= 23 && x < 46 && y >= 94 && y < 190) {
		should_fall = true;
		next_floor_y = 190;
	}
	if (x < 27 && y >= 69 && y < 89) {
		should_fall = true;
		next_floor_y = 89;
	}
	if (x >= 27 && x < 50 && y >= 69 && y < 81) {
		should_fall = true;
		next_floor_y = 81;
	}
	if (x >= 102 && x < 112 && y >= 71 && y < 126) {
		should_fall = true;
		next_floor_y = 126;
	}
	if (x >= 58 && x < 99 && y >= 106 && y < 194) {
		should_fall = true;
		next_floor_y = 194;
	}
	if (x >= 99 && x < 102 && y >= 103 && y < 126) {
		should_fall = true;
		next_floor_y = 126;
	}
	if (x >= 112 && x < 170.5f && y >= 93 && y < 126) {
		should_fall = true;
		next_floor_y = 126;
	}
	if (x >= 99 && x <= 101 && y >= 141 && y < 194) {
		should_fall = true;
		next_floor_y = 194;
	}
	if (x > 101 && x < 137 && y >= 141 && y < 190) {
		should_fall = true;
		next_floor_y = 190;
	}
	if (x >= 170.5f && x < 182 && y >= 91 && y < 190) {
		should_fall = true;
		next_floor_y = 190;
	}
	if (x >= 182 && x < 202 && y >= 91 && y < 126) {
		should_fall = true;
		next_floor_y = 126;
	}
	if (x >= 202 && x < 214 && y >= 92 && y < 190) {
		should_fall = true;
		next_floor_y = 190;
	}
	if (x >= 214 && x < 234 && y >= 92 && y < 126) {
		should_fall = true;
		next_floor_y = 126;
	}
	if (x >= 234 && x < 244 && y >= 92 && y < 161) {
		should_fall = true;
		next_floor_y = 161;
	}
	if (x >= 244 && x < 265 && y >= 92 && y < 129) {
		should_fall = true;
		next_floor_y = 129;
	}
	if (x >= 314 && x < 405 && y >= 55 && y < 73) {
		should_fall = true;
		next_floor_y = 73;
	}
	if (x >= 337 && x < 358 && y >= 86 && y < 101) {
		should_fall = true;
		next_floor_y = 101;
	}
	if (x >= 385 && x < 404 && y > 97 && y < 133) {
		should_fall = true;
		next_floor_y = 133;
	}if (x >= 358 && x < 385 && y > 86 && y < 156.5f) {
		should_fall = true;
		next_floor_y = 156.5f;
	}
	if (x >= 335 && x < 358 && y >= 116.5f && y < 156.5f) {
		should_fall = true;
		next_floor_y = 156.5f;
	}if (x >= 263 && x < 408 && y >= 170 && y < 197) {
		should_fall = true;
		next_floor_y = 197;
	}
	if (x >= 227 && x < 263 && y >= 193 && y < 197) {
		should_fall = true;
		next_floor_y = 197;
	}


	//
	// Check climbing
	// 
	//1st
	if (x >= 15 && x <= 20 && y >= 90 && y <= 189.9f) {
		climbing = true;
		should_fall = false;
	}
	//2nd
	if (x >= 78 && x <= 84 && y >= 29 && y <= 88.5f) {
		climbing = true;
		should_fall = false;
	}
	//3rd
	if (x >= 90 && x <= 96 && y >= 123 && y <= 193) {
		climbing = true;
		should_fall = false;
	}
	//4th
	if (x >= 213 && x <= 219 && y >= 29 && y <= 81) {
		climbing = true;
		should_fall = false;
	}
	//5th
	if (x >= 284.5f && x <= 290.5f && y >= 66 && y <= 160) {
		climbing = true;
		should_fall = false;
	}
	//6th
	if (x >= 308 && x <= 314 && y >= 96 && y <= 157) {
		climbing = true;
		should_fall = false;
	}
	//7th
	if (x >= 387.5f && x <= 393.5f && y >= 29 && y <= 72.5f) {
		climbing = true;
		should_fall = false;
	}
	//8th
	if (x >= 340 && x <= 346 && y >= 157 && y <= 196.5f) {
		climbing = true;
		should_fall = false;
	}



	//
	///Door
	//
	if (x >= 396.5f && x <= 406 && y >= 182 && y <= 202 && door) {

		x = 395.5f;
	}

	//
	/// crawling
	//

	if (x >= 267.5f && x <= 284 && y <= 128.3f && y >= 113 && !climbing) {
		crawling = true;
	}
	if (x >= 290.3f && x <= 307.8 && y <= 128.3 && y >= 113 && !climbing) {
		crawling = true;
	}
	if (x >= 246.8 && x <= 290 && y <= 159 && y >= 140 && !climbing) {
		crawling = true;
	}
	if (x > 314 && x <= 334.2f && y <= 156 && y >= 87 && !climbing) {
		crawling = true;
	}
	if (x > 290.5f && x <= 313.5f && y <= 72 && y >= 55.2f && !climbing) {
		crawling = true;
	}

	//
	// World Boundaries
	//
	// 
	//block jump in the top of ladder
	if (x >= 79 && x <= 83 && y >= 22 && y <= 29) {
		jumped = true;
		clip = true;
	}
	if (x >= 16 && x <= 20 && y >= 84 && y <= 90) {
		jumped = true;
		clip = true;
	}
	if (x >= 91 && x <= 96 && y >= 120 && y <= 123.5f && should_fall) {
		jumped = true;
		clip = true;
	}
	if (x >= 214.5f && x <= 218.5f && y >= 22 && y <= 29) {
		jumped = true;
		clip = true;
	}
	if (x >= 284.5f && x <= 290.5f && y >= 63 && y <= 69) {
		jumped = true;
		clip = true;
	}
	if (x >= 307 && x <= 314 && y >= 95 && y <= 98) {
		jumped = true;
		clip = true;
	}
	if (x >= 388.5f && x <= 392.5f && y >= 22 && y <= 29) {
		jumped = true;
		clip = true;
	}
	if (x >= 340 && x <= 346 && y >= 154 && y <= 157) {
		jumped = true;
		clip = true;
	}


	//block jump in the bot of ladder
	if (x >= 80 && x <= 82 && y >= 88.7f && y <= 91) {
		climbing = true;
		clip = true;
	}
	if (x >= 16 && x <= 20 && y >= 190 && y <= 193) {
		climbing = true;
		clip = true;
	}
	if (x >= 92 && x <= 94 && y >= 194 && y <= 194) {
		climbing = true;
		clip = true;
	}
	if (x >= 215.5f && x <= 217.5f && y >= 81.5f && y <= 84) {
		climbing = true;
		clip = true;
	}
	if (x >= 284.5f && x <= 290.5f && y >= 158 && y <= 161) {
		climbing = true;
		clip = true;
	}
	if (x >= 389.5f && x <= 391.5f && y >= 73 && y <= 76) {
		climbing = true;
		clip = true;
	}
	if (x >= 342 && x <= 344 && y >= 197 && y <= 200) {
		climbing = true;
		clip = true;
	}




	if (y >= 190 && x >= 170.5f && x < 182) {
		l_lives = true;
		cout << "lose life: " << l_lives << endl;
		clip = true;
		x = 53;
		y = 28.5f;
		return l_lives;
	}
	if (x >= 202 && x < 214 && y >= 190) {
		l_lives = true;
		clip = true;
		x = 53;
		y = 28.5f;
	}
	if (x >= 405 && y >= 181 && y <= 199) {
		x = 404;
		clip = true;
	}
	if (x < 10 && y < 100) {
		x = 10;
		clip = true;
	}
	if (x < 17 && y >= 100 && y < 138.5f) {
		x = 18;
		clip = true;
	}

	if (x > 391.5f && y > 31.5f && y <= 83) {
		x = 390.5f;
		clip = true;
	}

	if (x > 402 && y <= 31.5f) {
		x = 402;
		clip = true;
	}
	if (y > 83 && y < 140 && x > 401) {
		x = 401;
		clip = true;
	}
	if (y >= 162 && y < 181 && x >= 397.9f) {
		x = 397.9f;
		clip = true;
	}
	if (x > 229 && x <= 408 && y >= 198) {
		y = 197;
		clip = true;
	}
	if (x > 405 && x <= 408 && y >= 198 && y <= 202) {
		y = 197;
		x = 404.5;
		clip = true;
	}
	if (y <= 5 && x >= 0) {
		y = 6;
		clip = true;
	}
	if (x < 57 && y >= 191 && y < 199) {
		y = 190;
		clip = true;
	}
	else if (x >= 57 && x < 60.5f && y >= 191 && y < 199) {
		x = 61.5f;
		clip = true;
	}
	if (x < 17 && y >= 134 && y < 198) {
		x = 18;
		clip = true;
	}

	if (x < 12.5 && y >= 129 && y < 137) {
		y = 128;
		clip = true;
	}
	else if (x < 12.5 && y >= 137 && y < 145.5) {
		y = 145;
		clip = true;
	}
	else if (x <= 16 && x <= 12.5 && y >= 127.5 && y < 145.5) {
		x = 18;
		clip = true;
	}
	if (x < 13 && y >= 90 && y < 95) {
		y = 89;
		clip = true;
	}
	else if (x < 13 && y >= 95 && y < 104.5) {
		y = 105.5;
		clip = true;
	}
	else if (x >= 13 && x <= 17 && y >= 90 && y < 104.5) {
		x = 18;
		clip = true;
	}
	if (x >= 227 && x < 236.5 && y > 181 && y < 204) {
		x = 237.5;
		clip = true;
	}

	if (x >= 227 && x < 263 && y > 181 && y < 193.5f) {
		y = 194.5f;
		clip = true;
	}

	if (x >= 258 && x < 267 && y > 166 && y < 181) {
		x = 268;
		clip = true;
	}

	if (x >= 257 && x < 334 && y > 172 && y < 177) {
		y = 178;
		clip = true;
	}

	if (x >= 329 && x < 334 && y > 154 && y < 167) {
		x = 337;
		clip = true;
	}

	if (x >= 353 && x < 385 && y > 167 && y < 177) {
		y = 178;
		clip = true;
	}

	if (x >= 381 && x < 387 && y > 158 && y < 174) {
		x = 388;
		clip = true;
	}

	if (x >= 350 && x < 363 && y >= 157.5 && y <= 162) {
		y = 156.5;
		clip = true;
	}
	else if (x >= 350 && x < 363 && y > 162 && y < 173) {
		y = 174;
		clip = true;

	}
	else if (x >= 344 && x < 350 && y > 157.5 && y < 173) {
		x = 343;
		clip = true;

	}
	if (x >= 329 && x < 339 && y > 157.5 && y < 162) {
		y = 156.5;
		clip = true;
	}
	else if (x >= 329 && x < 339 && y > 162 && y < 173) {
		y = 174;
		clip = true;
	}
	else if (x >= 339 && x < 342 && y > 157.5 && y < 173) {
		x = 343;
		clip = true;
	}

	if (x >= 381 && x < 404 && y > 158 && y < 170) {
		y = 171;
		clip = true;

	}

	if (x > 385 && x < 404 && y > 87 && y < 97) {
		y = 98;
		clip = true;

	}

	if (x >= 380 && x < 386 && y > 83 && y < 93) {
		x = 379;
		clip = true;

	}

	if (x >= 310 && x < 405 && y > 74 && y <= 83) {
		y = 73;
		clip = true;
	}
	else if (x >= 310 && x < 405 && y > 83 && y <= 88) {
		y = 89.5;
		clip = true;
	}
	if (x >= 329 && x < 335 && y > 83 && y <= 91) {
		x = 336;
		clip = true;
	}
	if (x >= 306 && x < 335 && y > 87 && y <= 97) {
		y = 98;
		clip = true;
	}
	if (x >= 306 && x <= 337 && y >= 155 && y < 160) {
		y = 154;
		clip = true;
	}
	if (x >= 316 && x < 335 && y > 143 && y <= 153) {
		y = 154;
		clip = true;
	}
	if (x >= 329 && x < 336 && y >= 101 && y < 148) {
		x = 339;
		clip = true;
	}
	else if (x >= 312 && x < 329 && y >= 100 && y < 148) {
		x = 311;
		clip = true;
	}
	if (x >= 316 && x <= 338 && y >= 99 && y <= 102) {
		y = 98;
		clip = true;
	}
	if (x >= 329 && x < 358 && y >= 102 && y < 109) {
		y = 101;
		clip = true;
	}
	else if (x >= 329 && x < 358 && y >= 109 && y < 116.5f) {
		y = 117.5f;
		clip = true;
	}
	if (x >= 384 && x < 407 && y >= 134 && y < 143) {
		y = 133;
		clip = true;
	}
	if (x >= 305 && x < 310 && y >= 127 && y < 158) {
		x = 311;
		clip = true;
	}
	if (x >= 305 && x < 310 && y >= 87 && y < 124) {
		x = 311;
		clip = true;
	}
	if (x >= 290 && x < 311 && y >= 115 && y < 125) {
		y = 126;
		clip = true;
	}
	if (x >= 290 && x < 311 && y >= 127 && y < 130) {
		y = 126;
		clip = true;
	}
	if (x >= 288.5f && x < 294 && y >= 127 && y < 161) {
		x = 287.5f;
		clip = true;
	}
	if (x >= 288.5f && x < 294 && y >= 70 && y < 124) {
		x = 287.5f;
		clip = true;
	}
	if (x >= 281 && x < 286.5f && y >= 59 && y < 124) {
		x = 287.5f;
		clip = true;
	}
	if (x >= 281 && x < 286.5f && y >= 127 && y < 153) {
		x = 287.5f;
		clip = true;
	}
	if (x >= 292 && x < 315 && y >= 70 && y < 83) {
		y = 69;
		clip = true;
	}
	if (x >= 282 && x < 315 && y >= 59 && y < 68) {
		y = 69;
		clip = true;
	}
	if (x >= 265 && x < 285 && y >= 115 && y < 125) {
		y = 126;
		clip = true;
	}
	if (x >= 265 && x < 285 && y >= 127 && y < 133) {
		y = 126;
		clip = true;
	}
	if (x >= 245 && x < 286 && y >= 144 && y < 158) {
		y = 158;
		clip = true;
	}
	if (x >= 245 && x < 294 && y >= 159 && y < 166) {
		y = 158;
		clip = true;
	}
	if (x >= 242.5 && x < 251 && y >= 134 && y < 154) {
		x = 241.5;
		clip = true;
	}
	if (x >= 244 && x < 271 && y >= 130 && y < 154) {
		y = 129;
		clip = true;
	}
	if (x >= 309 && x < 318 && y >= 46 && y < 67) {
		x = 319;
		clip = true;
	}
	if (x >= 309 && x < 381 && y >= 46 && y < 58) {
		y = 59;
		clip = true;
	}
	if (x >= 376 && x < 389.5f && y >= 31.5f && y < 58) {
		x = 390.5f;
		clip = true;
	}
	if (x >= 395 && y >= 29.5f && y < 43) {
		y = 28.5f;
		clip = true;
	}
	else if (x >= 395 && y >= 44 && y < 48) {
		y = 46;
		clip = true;
	}
	else if (x >= 391.5f && x > 395 && y >= 31.5f && y < 47) {
		x = 390.5f;
		clip = true;
	}
	if (x >= 221 && x < 386 && y >= 29.5f && y < 43) {
		y = 28.5f;
		clip = true;
	}
	else if (x >= 217 && x < 221 && y >= 29.5f && y < 43) {
		x = 216;
		clip = true;
	}
	else if (x >= 386 && x < 389.5f && y >= 31.5f && y < 43) {
		x = 390.5f;
		clip = true;
	}
	if (x >= 88 && x < 211 && y >= 29.5f && y < 43) {
		y = 28.5f;
		clip = true;
	}
	else if (x >= 211 && x < 215 && y >= 29.5f && y < 43) {
		x = 216;
		clip = true;
	}
	if (x <= 76 && y >= 29.5f && y < 43) {
		y = 28.5f;
		clip = true;
	}
	if (x >= 264 && x <= 271 && y >= 85 && y < 123) {
		x = 263;
		clip = true;
	}
	if (x >= 198 && x <= 271 && y >= 82.5f && y < 90) {
		y = 81.5f;
		clip = true;
	}
	else if (x >= 198 && x <= 271 && y >= 90 && y < 95.5) {
		y = 96.5;
		clip = true;
	}
	if (x >= 259.5 && x <= 267 && y >= 52 && y < 95) {
		x = 258.5;
		clip = true;
	}
	if (x >= 220 && x <= 267 && y >= 52 && y < 64.5) {
		y = 65.5;
		clip = true;
	}
	if (x >= 217.5f && x <= 232 && y >= 29.5f && y < 64) {
		x = 216.5f;
		clip = true;
	}
	if (x > 208 && x <= 215.5f && y >= 29.5f && y < 60) {
		x = 216.5f;
		clip = true;
	}
	else if (x >= 199 && x <= 208 && y >= 29.5f && y < 60) {
		x = 198;
		clip = true;
	}
	else if (x >= 200 && x <= 215.5f && y >= 60 && y < 67) {
		y = 67;
		clip = true;
	}
	if (x >= 115 && x <= 215 && y >= 49 && y < 61) {
		y = 62;
		clip = true;
	}
	if (x >= 112 && x < 118 && y >= 49 && y < 93) {
		x = 111;
		clip = true;
	}
	else if (x >= 118 && x <= 125 && y >= 49 && y < 93) {
		x = 126;
		clip = true;
	}
	if (x >= 112 && x < 201 && y >= 77.5f && y < 83) {
		y = 76.5f;
		clip = true;
	}
	else if (x >= 201 && x < 204 && y >= 78.5f && y < 83) {
		x = 205;
		clip = true;
	}
	else if (x >= 112 && x < 204 && y >= 83 && y < 93) {
		y = 94;
		clip = true;
	}
	if (x >= 231 && x < 250 && y >= 162 && y < 172) {
		y = 161;
		clip = true;
	}
	if (x >= 230 && x < 238 && y >= 127 && y < 172.5) {
		x = 239;
		clip = true;
	}
	if (x >= 214 && x < 234 && y >= 127 && y < 136) {
		y = 126;
		clip = true;
	}
	if (x >= 211 && x < 220 && y >= 127 && y < 199) {
		x = 210;
		clip = true;
	}
	if (x >= 198 && x < 219 && y >= 191 && y < 199) {
		y = 190;
		clip = true;
	}
	if (x >= 198 && x < 206 && y >= 127 && y < 199) {
		x = 207;
		clip = true;
	}
	if (x >= 182 && x < 202 && y >= 127 && y < 136) {
		y = 126;
		clip = true;
	}
	if (x >= 178 && x < 188 && y >= 127 && y < 199) {
		x = 177;
		clip = true;
	}
	if (x >= 168 && x < 188 && y >= 191 && y < 199) {
		y = 190;
		clip = true;
	}
	if (x >= 166 && x < 174 && y >= 127 && y < 199) {
		x = 175;
		clip = true;
	}
	if (x >= 99 && x < 170.5f && y >= 127 && y < 132) {
		y = 126;
		clip = true;
	}
	else if (x >= 99 && x < 171 && y >= 132 && y < 141) {
		y = 142;
		clip = true;
	}
	if (x >= 127 && x < 137 && y >= 127 && y < 199) {
		x = 126;
		clip = true;
	}
	if (x >= 104 && x < 137 && y >= 191 && y < 199) {
		y = 190;
		clip = true;
	}
	else if (x >= 101 && x < 104 && y >= 191 && y < 199) {
		x = 101;
		clip = true;
	}
	if (x >= 56.5 && x < 109 && y >= 195 && y < 202) {
		y = 194;
		clip = true;
	}
	if (x >= 19 && x < 32 && y >= 100 && y < 180) {
		x = 18;
		clip = true;
	}
	else if (x >= 32 && x < 36 && y >= 86 && y < 180) {
		x = 37.5f;
		clip = true;
	}
	else if (x >= 24 && x < 32 && y >= 86 && y < 100) {
		x = 23;
	}
	if (x >= 23 && x < 35 && y >= 90 && y < 99) {
		y = 89;
		clip = true;
	}
	else if (x >= 19 && x < 23 && y >= 90 && y < 106) {
		x = 18;
		clip = true;
	}
	if (x >= 27 && x < 50 && y >= 82 && y < 87) {
		y = 81;
		clip = true;
	}
	else if (x >= 29 && x < 52 && y >= 87 && y < 98) {
		y = 99;
		clip = true;
	}
	if (x < 50 && y >= 58 && y < 69.5f) {
		y = 70.5f;
		clip = true;
	}
	if (x >= 40 && x < 47 && y >= 58 && y < 96) {
		x = 39;
		clip = true;
	}
	else if (x >= 47 && x < 51 && y >= 58 && y < 95) {
		x = 52;
		clip = true;
	}
	if (x >= 45 && x < 78 && y >= 56 && y < 73) {
		y = 74;
		clip = true;
	}
	if (x >= 69 && x < 80 && y >= 29.5 && y < 74) {
		x = 81;
		clip = true;
	}
	if (x >= 82 && x < 97 && y >= 29.5 && y < 74) {
		x = 81;
		clip = true;
	}
	if (x >= 85 && x < 120 && y >= 62 && y < 73) {
		y = 74;
		clip = true;
	}
	if (x >= 58 && x < 102 && y >= 89.7f && y < 98) {
		y = 88.7f;
		clip = true;
	}
	else if (x >= 58 && x < 102 && y >= 98 && y < 106) {
		y = 107;
		clip = true;
	}
	if (x >= 143 && x < 157 && y >= 85 && y < 109) {
		x = 142;
		clip = true;
	}
	else if (x >= 157 && x < 171.5f && y >= 85 && y < 109) {
		x = 172.5f;
		clip = true;
	}
	else if (x > 152 && x < 168 && y >= 101 && y < 113.5f) {
		y = 114.5f;
		clip = true;
	}
	else if (x >= 146.5 && x <= 152 && y >= 102 && y < 115) {
		y = 116;
		clip = true;
	}
	if (x >= 379 && x < 385 && y >= 135 && y <= 141) {
		x = 378;
		y = 142;
		clip = true;
	}
	else if (x >= 373 && x < 385 && y >= 141 && y <= 145) {
		x = 372;
		y = 146;
		clip = true;
	}
	else if (x >= 367 && x < 385 && y >= 145 && y <= 149) {
		x = 366;
		y = 150;
		clip = true;
	}
	else if (x >= 361 && x < 385 && y >= 149 && y <= 153) {
		x = 360;
		y = 154;
		clip = true;
	}
	else if (x >= 360 && x < 385 && y >= 153 && y <= 156.5f) {
		x = 358;
		y = 156.5f;
		clip = true;
	}

	return clip;

}