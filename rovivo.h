/*
 * ROVIVO library for modifications
 * 
 */


//LoveHeart ausgeben
void setLH() {
   if (heartnr >= 6)
      heartnr = 1;
    else
      heartnr++;
  switch (heartnr)
    {
     case 1:
     matrix[0]  = 0b0000000000000000;
     matrix[1]  = 0b0000000000000000;
     matrix[2]  = 0b0000000000000000;
     matrix[3]  = 0b0000101000000000;
     matrix[4]  = 0b0001111100000000;
     matrix[5]  = 0b0000111000000000;
     matrix[6]  = 0b0000010000000000;
     matrix[7]  = 0b0000000000000000;
     matrix[8]  = 0b0000000000000000;
     matrix[9]  = 0b0000000000000000;
     matrix[10] = 0b0000000000000000;
     matrix[11] = 0b0000000000000000;
     matrix[12] = 0b0000000000000000;
     matrix[13] = 0b0000000000000000;
     matrix[14] = 0b0000000000000000;
     matrix[15] = 0b0000000000000000;
     break;
     case 2:
     matrix[0]  = 0b0000000000000000;
     matrix[1]  = 0b0011101110000000;
     matrix[2]  = 0b0100010001000000;
     matrix[3]  = 0b0100000001000000;
     matrix[4]  = 0b0100000001000000;
     matrix[5]  = 0b0010000010000000;
     matrix[6]  = 0b0001000100000000;
     matrix[7]  = 0b0000101000000000;
     matrix[8]  = 0b0000010000000000;
     matrix[9]  = 0b0000000000000000;
     matrix[10] = 0b0000000000000000;
     matrix[11] = 0b0000000000000000;
     matrix[12] = 0b0000000000000000;
     matrix[13] = 0b0000000000000000;
     matrix[14] = 0b0000000000000000;
     matrix[15] = 0b0000000000000000;
     break;
     case 3:
     matrix[0]  = 0b0011101110000000;
     matrix[1]  = 0b0100010001000000;
     matrix[2]  = 0b1000010000100000;
     matrix[3]  = 0b1000000000100000;
     matrix[4]  = 0b1000000000100000;
     matrix[5]  = 0b0100000001000000;
     matrix[6]  = 0b0010000010000000;
     matrix[7]  = 0b0001000100000000;
     matrix[8]  = 0b0000101000000000;
     matrix[9]  = 0b0000010000000000;
     matrix[10] = 0b0000000000000000;
     matrix[11] = 0b0000000000000000;
     matrix[12] = 0b0000000000000000;
     matrix[13] = 0b0000000000000000;
     matrix[14] = 0b0000000000000000;
     matrix[15] = 0b0000000000000000;
     break; 
     case 4:
     matrix[0]  = 0b0011101110000000;
     matrix[1]  = 0b0111111111000000;
     matrix[2]  = 0b1100010001100000;
     matrix[3]  = 0b1100000001100000;
     matrix[4]  = 0b1100000001100000;
     matrix[5]  = 0b0110000011000000;
     matrix[6]  = 0b0011000110000000;
     matrix[7]  = 0b0001101100000000;
     matrix[8]  = 0b0000111000000000;
     matrix[9]  = 0b0000010000000000;
     matrix[10] = 0b0000000000000000;
     matrix[11] = 0b0000000000000000;
     matrix[12] = 0b0000000000000000;
     matrix[13] = 0b0000000000000000;
     matrix[14] = 0b0000000000000000;
     matrix[15] = 0b0000000000000000;
     break;
     case 5:
     matrix[0]  = 0b0011101110000000;
     matrix[1]  = 0b0111111111000000;
     matrix[2]  = 0b1111111111100000;
     matrix[3]  = 0b1110010011100000;
     matrix[4]  = 0b1110000011100000;
     matrix[5]  = 0b0111000111000000;
     matrix[6]  = 0b0011101110000000;
     matrix[7]  = 0b0001111100000000;
     matrix[8]  = 0b0000111000000000;
     matrix[9]  = 0b0000010000000000;
     matrix[10] = 0b0000000000000000;
     matrix[11] = 0b0000000000000000;
     matrix[12] = 0b0000000000000000;
     matrix[13] = 0b0000000000000000;
     matrix[14] = 0b0000000000000000;
     matrix[15] = 0b0000000000000000;
     break;
     case 6:
     matrix[0]  = 0b0011101110000000;
     matrix[1]  = 0b0111111111000000;
     matrix[2]  = 0b1111111111100000;
     matrix[3]  = 0b1111111111100000;
     matrix[4]  = 0b1111111111100000;
     matrix[5]  = 0b0111111111000000;
     matrix[6]  = 0b0011111110000000;
     matrix[7]  = 0b0001111100000000;
     matrix[8]  = 0b0000111000000000;
     matrix[9]  = 0b0000010000000000;
     matrix[10] = 0b0000000000000000;
     matrix[11] = 0b0000000000000000;
     matrix[12] = 0b0000000000000000;
     matrix[13] = 0b0000000000000000;
     matrix[14] = 0b0000000000000000;
     matrix[15] = 0b0000000000000000;
     break;
  }
}

//Schweizerkreuz ausgeben
void setNFT() {
    if (Nnr >= 3)
      Nnr = 1;
    else
      Nnr++;
  
  switch (Nnr)
    {
     case 1:
     matrix[0]  = 0b0000000000000000;
     matrix[1]  = 0b0000000000000000;
     matrix[2]  = 0b0000000000000000;
     matrix[3]  = 0b0000010000000000;
     matrix[4]  = 0b0000111000000000;
     matrix[5]  = 0b0000010000000000;
     matrix[6]  = 0b0000000000000000;
     matrix[7]  = 0b0000000000000000;
     matrix[8]  = 0b0000000000000000;
     matrix[9]  = 0b0000000000000000;
     matrix[10] = 0b0000000000000000;
     matrix[11] = 0b0000000000000000;
     matrix[12] = 0b0000000000000000;
     matrix[13] = 0b0000000000000000;
     matrix[14] = 0b0000000000000000;
     matrix[15] = 0b0000000000000000;
     break;
     case 2:
     matrix[0]  = 0b0000111000000000;
     matrix[1]  = 0b0000111000000000;
     matrix[2]  = 0b0000111000000000;
     matrix[3]  = 0b0111111111000000;
     matrix[4]  = 0b0111111111000000;
     matrix[5]  = 0b0111111111000000;
     matrix[6]  = 0b0000111000000000;
     matrix[7]  = 0b0000111000000000;
     matrix[8]  = 0b0000111000000000;
     matrix[9]  = 0b0000000000000000;
     matrix[10] = 0b0000000000000000;
     matrix[11] = 0b0000000000000000;
     matrix[12] = 0b0000000000000000;
     matrix[13] = 0b0000000000000000;
     matrix[14] = 0b0000000000000000;
     matrix[15] = 0b0000000000000000;
     break;
     case 3:
     matrix[0]  = 0b0000111000000000;
     matrix[1]  = 0b0000111000000000;
     matrix[2]  = 0b0000111000000000;
     matrix[3]  = 0b0111101111000000;
     matrix[4]  = 0b0111000111000000;
     matrix[5]  = 0b0111101111000000;
     matrix[6]  = 0b0000111000000000;
     matrix[7]  = 0b0000111000000000;
     matrix[8]  = 0b0000111000000000;
     matrix[9]  = 0b0000000000000000;
     matrix[10] = 0b0000000000000000;
     matrix[11] = 0b0000000000000000;
     matrix[12] = 0b0000000000000000;
     matrix[13] = 0b0000000000000000;
     matrix[14] = 0b0000000000000000;
     matrix[15] = 0b0000000000000000;
     break;
  }
}
  //Rovivo Testmodus um "bad" Leds zu finden
void setTEST() {
   if (testnr >= 21)
      testnr = 1;
    else
      testnr++;
  switch (testnr)
    {
  case 1:
     matrix[0]  = 0b1111111111111111;
     matrix[1]  = 0b0000000000000000;
     matrix[2]  = 0b0000000000000000;
     matrix[3]  = 0b0000000000000000;
     matrix[4]  = 0b0000000000000000;
     matrix[5]  = 0b0000000000000000;
     matrix[6]  = 0b0000000000000000;
     matrix[7]  = 0b0000000000000000;
     matrix[8]  = 0b0000000000000000;
     matrix[9]  = 0b0000000000000000;
     matrix[10] = 0b0000000000000000;
     matrix[11] = 0b0000000000000000;
     matrix[12] = 0b0000000000000000;
     matrix[13] = 0b0000000000000000;
     matrix[14] = 0b0000000000000000;
     matrix[15] = 0b0000000000000000;
     break;
  case 2:
     matrix[0]  = 0b0000000000000000;
     matrix[1]  = 0b1111111111111111;
     matrix[2]  = 0b0000000000000000;
     matrix[3]  = 0b0000000000000000;
     matrix[4]  = 0b0000000000000000;
     matrix[5]  = 0b0000000000000000;
     matrix[6]  = 0b0000000000000000;
     matrix[7]  = 0b0000000000000000;
     matrix[8]  = 0b0000000000000000;
     matrix[9]  = 0b0000000000000000;
     matrix[10] = 0b0000000000000000;
     matrix[11] = 0b0000000000000000;
     matrix[12] = 0b0000000000000000;
     matrix[13] = 0b0000000000000000;
     matrix[14] = 0b0000000000000000;
     matrix[15] = 0b0000000000000000;
     break;
  case 3:
     matrix[0]  = 0b0000000000000000;
     matrix[1]  = 0b0000000000000000;
     matrix[2]  = 0b1111111111111111;
     matrix[3]  = 0b0000000000000000;
     matrix[4]  = 0b0000000000000000;
     matrix[5]  = 0b0000000000000000;
     matrix[6]  = 0b0000000000000000;
     matrix[7]  = 0b0000000000000000;
     matrix[8]  = 0b0000000000000000;
     matrix[9]  = 0b0000000000000000;
     matrix[10] = 0b0000000000000000;
     matrix[11] = 0b0000000000000000;
     matrix[12] = 0b0000000000000000;
     matrix[13] = 0b0000000000000000;
     matrix[14] = 0b0000000000000000;
     matrix[15] = 0b0000000000000000;
     break;
  case 4:
     matrix[0]  = 0b0000000000000000;
     matrix[1]  = 0b0000000000000000;
     matrix[2]  = 0b0000000000000000;
     matrix[3]  = 0b1111111111111111;
     matrix[4]  = 0b0000000000000000;
     matrix[5]  = 0b0000000000000000;
     matrix[6]  = 0b0000000000000000;
     matrix[7]  = 0b0000000000000000;
     matrix[8]  = 0b0000000000000000;
     matrix[9]  = 0b0000000000000000;
     matrix[10] = 0b0000000000000000;
     matrix[11] = 0b0000000000000000;
     matrix[12] = 0b0000000000000000;
     matrix[13] = 0b0000000000000000;
     matrix[14] = 0b0000000000000000;
     matrix[15] = 0b0000000000000000;
     break;
  case 5:
     matrix[0]  = 0b0000000000000000;
     matrix[1]  = 0b0000000000000000;
     matrix[2]  = 0b0000000000000000;
     matrix[3]  = 0b0000000000000000;
     matrix[4]  = 0b1111111111111111;
     matrix[5]  = 0b0000000000000000;
     matrix[6]  = 0b0000000000000000;
     matrix[7]  = 0b0000000000000000;
     matrix[8]  = 0b0000000000000000;
     matrix[9]  = 0b0000000000000000;
     matrix[10] = 0b0000000000000000;
     matrix[11] = 0b0000000000000000;
     matrix[12] = 0b0000000000000000;
     matrix[13] = 0b0000000000000000;
     matrix[14] = 0b0000000000000000;
     matrix[15] = 0b0000000000000000;
     break;
  case 6:
     matrix[0]  = 0b0000000000000000;
     matrix[1]  = 0b0000000000000000;
     matrix[2]  = 0b0000000000000000;
     matrix[3]  = 0b0000000000000000;
     matrix[4]  = 0b0000000000000000;
     matrix[5]  = 0b1111111111111111;
     matrix[6]  = 0b0000000000000000;
     matrix[7]  = 0b0000000000000000;
     matrix[8]  = 0b0000000000000000;
     matrix[9]  = 0b0000000000000000;
     matrix[10] = 0b0000000000000000;
     matrix[11] = 0b0000000000000000;
     matrix[12] = 0b0000000000000000;
     matrix[13] = 0b0000000000000000;
     matrix[14] = 0b0000000000000000;
     matrix[15] = 0b0000000000000000;
     break;
  case 7:
     matrix[0]  = 0b0000000000000000;
     matrix[1]  = 0b0000000000000000;
     matrix[2]  = 0b0000000000000000;
     matrix[3]  = 0b0000000000000000;
     matrix[4]  = 0b0000000000000000;
     matrix[5]  = 0b0000000000000000;
     matrix[6]  = 0b1111111111111111;
     matrix[7]  = 0b0000000000000000;
     matrix[8]  = 0b0000000000000000;
     matrix[9]  = 0b0000000000000000;
     matrix[10] = 0b0000000000000000;
     matrix[11] = 0b0000000000000000;
     matrix[12] = 0b0000000000000000;
     matrix[13] = 0b0000000000000000;
     matrix[14] = 0b0000000000000000;
     matrix[15] = 0b0000000000000000;
     break;
  case 8:
     matrix[0]  = 0b0000000000000000;
     matrix[1]  = 0b0000000000000000;
     matrix[2]  = 0b0000000000000000;
     matrix[3]  = 0b0000000000000000;
     matrix[4]  = 0b0000000000000000;
     matrix[5]  = 0b0000000000000000;
     matrix[6]  = 0b0000000000000000;
     matrix[7]  = 0b1111111111111111;
     matrix[8]  = 0b0000000000000000;
     matrix[9]  = 0b0000000000000000;
     matrix[10] = 0b0000000000000000;
     matrix[11] = 0b0000000000000000;
     matrix[12] = 0b0000000000000000;
     matrix[13] = 0b0000000000000000;
     matrix[14] = 0b0000000000000000;
     matrix[15] = 0b0000000000000000;
     break;
  case 9:
     matrix[0]  = 0b0000000000000000;
     matrix[1]  = 0b0000000000000000;
     matrix[2]  = 0b0000000000000000;
     matrix[3]  = 0b0000000000000000;
     matrix[4]  = 0b0000000000000000;
     matrix[5]  = 0b0000000000000000;
     matrix[6]  = 0b0000000000000000;
     matrix[7]  = 0b0000000000000000;
     matrix[8]  = 0b1111111111111111;
     matrix[9]  = 0b0000000000000000;
     matrix[10] = 0b0000000000000000;
     matrix[11] = 0b0000000000000000;
     matrix[12] = 0b0000000000000000;
     matrix[13] = 0b0000000000000000;
     matrix[14] = 0b0000000000000000;
     matrix[15] = 0b0000000000000000;
     break;
  case 10:
     matrix[0]  = 0b0000000000000000;
     matrix[1]  = 0b0000000000000000;
     matrix[2]  = 0b0000000000000000;
     matrix[3]  = 0b0000000000000000;
     matrix[4]  = 0b0000000000000000;
     matrix[5]  = 0b0000000000000000;
     matrix[6]  = 0b0000000000000000;
     matrix[7]  = 0b0000000000000000;
     matrix[8]  = 0b0000000000000000;
     matrix[9]  = 0b1111111111111111;
     matrix[10] = 0b0000000000000000;
     matrix[11] = 0b0000000000000000;
     matrix[12] = 0b0000000000000000;
     matrix[13] = 0b0000000000000000;
     matrix[14] = 0b0000000000000000;
     matrix[15] = 0b0000000000000000;
     break;
  case 11:
     matrix[0]  = 0b1000000000000000;
     matrix[1]  = 0b1000000000000000;
     matrix[2]  = 0b1000000000000000;
     matrix[3]  = 0b1000000000000000;
     matrix[4]  = 0b1000000000000000;
     matrix[5]  = 0b1000000000000000;
     matrix[6]  = 0b1000000000000000;
     matrix[7]  = 0b1000000000000000;
     matrix[8]  = 0b1000000000000000;
     matrix[9]  = 0b1000000000000000;
     matrix[10] = 0b1000000000000000;
     matrix[11] = 0b1000000000000000;
     matrix[12] = 0b1000000000000000;
     matrix[13] = 0b1000000000000000;
     matrix[14] = 0b1000000000000000;
     matrix[15] = 0b1000000000000000;
     break;
  case 12:
     matrix[0]  = 0b0100000000000000;
     matrix[1]  = 0b0100000000000000;
     matrix[2]  = 0b0100000000000000;
     matrix[3]  = 0b0100000000000000;
     matrix[4]  = 0b0100000000000000;
     matrix[5]  = 0b0100000000000000;
     matrix[6]  = 0b0100000000000000;
     matrix[7]  = 0b0100000000000000;
     matrix[8]  = 0b0100000000000000;
     matrix[9]  = 0b0100000000000000;
     matrix[10] = 0b0100000000000000;
     matrix[11] = 0b0100000000000000;
     matrix[12] = 0b0100000000000000;
     matrix[13] = 0b0100000000000000;
     matrix[14] = 0b0100000000000000;
     matrix[15] = 0b0100000000000000;
     break;
  case 13:
     matrix[0]  = 0b0010000000000000;
     matrix[1]  = 0b0010000000000000;
     matrix[2]  = 0b0010000000000000;
     matrix[3]  = 0b0010000000000000;
     matrix[4]  = 0b0010000000000000;
     matrix[5]  = 0b0010000000000000;
     matrix[6]  = 0b0010000000000000;
     matrix[7]  = 0b0010000000000000;
     matrix[8]  = 0b0010000000000000;
     matrix[9]  = 0b0010000000000000;
     matrix[10] = 0b0010000000000000;
     matrix[11] = 0b0010000000000000;
     matrix[12] = 0b0010000000000000;
     matrix[13] = 0b0010000000000000;
     matrix[14] = 0b0010000000000000;
     matrix[15] = 0b0010000000000000;
     break;
  case 14:
     matrix[0]  = 0b0001000000000000;
     matrix[1]  = 0b0001000000000000;
     matrix[2]  = 0b0001000000000000;
     matrix[3]  = 0b0001000000000000;
     matrix[4]  = 0b0001000000000000;
     matrix[5]  = 0b0001000000000000;
     matrix[6]  = 0b0001000000000000;
     matrix[7]  = 0b0001000000000000;
     matrix[8]  = 0b0001000000000000;
     matrix[9]  = 0b0001000000000000;
     matrix[10] = 0b0001000000000000;
     matrix[11] = 0b0001000000000000;
     matrix[12] = 0b0001000000000000;
     matrix[13] = 0b0001000000000000;
     matrix[14] = 0b0001000000000000;
     matrix[15] = 0b0001000000000000;
     break;
  case 15:
     matrix[0]  = 0b0000100000000000;
     matrix[1]  = 0b0000100000000000;
     matrix[2]  = 0b0000100000000000;
     matrix[3]  = 0b0000100000000000;
     matrix[4]  = 0b0000100000000000;
     matrix[5]  = 0b0000100000000000;
     matrix[6]  = 0b0000100000000000;
     matrix[7]  = 0b0000100000000000;
     matrix[8]  = 0b0000100000000000;
     matrix[9]  = 0b0000100000000000;
     matrix[10] = 0b0000100000000000;
     matrix[11] = 0b0000100000000000;
     matrix[12] = 0b0000100000000000;
     matrix[13] = 0b0000100000000000;
     matrix[14] = 0b0000100000000000;
     matrix[15] = 0b0000100000000000;
     break;
  case 16:
     matrix[0]  = 0b0000010000000000;
     matrix[1]  = 0b0000010000000000;
     matrix[2]  = 0b0000010000000000;
     matrix[3]  = 0b0000010000000000;
     matrix[4]  = 0b0000010000000000;
     matrix[5]  = 0b0000010000000000;
     matrix[6]  = 0b0000010000000000;
     matrix[7]  = 0b0000010000000000;
     matrix[8]  = 0b0000010000000000;
     matrix[9]  = 0b0000010000000000;
     matrix[10] = 0b0000010000000000;
     matrix[11] = 0b0000010000000000;
     matrix[12] = 0b0000010000000000;
     matrix[13] = 0b0000010000000000;
     matrix[14] = 0b0000010000000000;
     matrix[15] = 0b0000010000000000;
     break;
  case 17:
     matrix[0]  = 0b0000001000000000;
     matrix[1]  = 0b0000001000000000;
     matrix[2]  = 0b0000001000000000;
     matrix[3]  = 0b0000001000000000;
     matrix[4]  = 0b0000001000000000;
     matrix[5]  = 0b0000001000000000;
     matrix[6]  = 0b0000001000000000;
     matrix[7]  = 0b0000001000000000;
     matrix[8]  = 0b0000001000000000;
     matrix[9]  = 0b0000001000000000;
     matrix[10] = 0b0000001000000000;
     matrix[11] = 0b0000001000000000;
     matrix[12] = 0b0000001000000000;
     matrix[13] = 0b0000001000000000;
     matrix[14] = 0b0000001000000000;
     matrix[15] = 0b0000001000000000;
     break;
  case 18:
     matrix[0]  = 0b0000000100000000;
     matrix[1]  = 0b0000000100000000;
     matrix[2]  = 0b0000000100000000;
     matrix[3]  = 0b0000000100000000;
     matrix[4]  = 0b0000000100000000;
     matrix[5]  = 0b0000000100000000;
     matrix[6]  = 0b0000000100000000;
     matrix[7]  = 0b0000000100000000;
     matrix[8]  = 0b0000000100000000;
     matrix[9]  = 0b0000000100000000;
     matrix[10] = 0b0000000100000000;
     matrix[11] = 0b0000000100000000;
     matrix[12] = 0b0000000100000000;
     matrix[13] = 0b0000000100000000;
     matrix[14] = 0b0000000100000000;
     matrix[15] = 0b0000000100000000;
     break;
  case 19:
     matrix[0]  = 0b0000000010000000;
     matrix[1]  = 0b0000000010000000;
     matrix[2]  = 0b0000000010000000;
     matrix[3]  = 0b0000000010000000;
     matrix[4]  = 0b0000000010000000;
     matrix[5]  = 0b0000000010000000;
     matrix[6]  = 0b0000000010000000;
     matrix[7]  = 0b0000000010000000;
     matrix[8]  = 0b0000000010000000;
     matrix[9]  = 0b0000000010000000;
     matrix[10] = 0b0000000010000000;
     matrix[11] = 0b0000000010000000;
     matrix[12] = 0b0000000010000000;
     matrix[13] = 0b0000000010000000;
     matrix[14] = 0b0000000010000000;
     matrix[15] = 0b0000000010000000;
     break;
  case 20:
     matrix[0]  = 0b0000000001000000;
     matrix[1]  = 0b0000000001000000;
     matrix[2]  = 0b0000000001000000;
     matrix[3]  = 0b0000000001000000;
     matrix[4]  = 0b0000000001000000;
     matrix[5]  = 0b0000000001000000;
     matrix[6]  = 0b0000000001000000;
     matrix[7]  = 0b0000000001000000;
     matrix[8]  = 0b0000000001000000;
     matrix[9]  = 0b0000000001000000;
     matrix[10] = 0b0000000001000000;
     matrix[11] = 0b0000000001000000;
     matrix[12] = 0b0000000001000000;
     matrix[13] = 0b0000000001000000;
     matrix[14] = 0b0000000001000000;
     matrix[15] = 0b0000000001000000;
     break;
  case 21:
     matrix[0]  = 0b0000000000100000;
     matrix[1]  = 0b0000000000100000;
     matrix[2]  = 0b0000000000100000;
     matrix[3]  = 0b0000000000100000;
     matrix[4]  = 0b0000000000100000;
     matrix[5]  = 0b0000000000100000;
     matrix[6]  = 0b0000000000100000;
     matrix[7]  = 0b0000000000100000;
     matrix[8]  = 0b0000000000100000;
     matrix[9]  = 0b0000000000100000;
     matrix[10] = 0b0000000000100000;
     matrix[11] = 0b0000000000100000;
     matrix[12] = 0b0000000000100000;
     matrix[13] = 0b0000000000100000;
     matrix[14] = 0b0000000000100000;
     matrix[15] = 0b0000000000100000;
     break;
    }
}