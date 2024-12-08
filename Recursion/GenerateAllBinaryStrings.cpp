// link - https://www.geeksforgeeks.org/generate-binary-strings-without-consecutive-1s/?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=generate-binary-strings-without-consecutive-1s

// Generate all binary strings without consecutive 1’s
// Last Updated : 30 Jul, 2024
// Given an integer, K. Generate all binary strings of size k without consecutive 1’s.

// Examples: 

// Input : K = 3  
// Output : 000 , 001 , 010 , 100 , 101 
// Input : K  = 4 
// Output :0000 0001 0010 0100 0101 1000 1001 1010
// Idea behind that is IF string ends with ‘1’ then we put only ‘0’ at the end. IF string ends with ‘0’ then we put both ‘0’ and ‘1’ at the end of string for generating new string.

// Below is algorithm  

// K : size of string 
// First We Generate All string starts with '0'
// initialize n = 1 . 
// GenerateALLString ( K  , Str , n )
//   a. IF n == K 
//      PRINT str.
//   b. IF previous character is '1' :: str[n-1] == '1'
//      put str[n] = '0'
//      GenerateAllString ( K , str , n+1 )
//   c. IF previous character is '0' :: str[n-1] == '0'
//      First We Put zero at end and call function 
//       PUT  str[n] = '0'
//            GenerateAllString ( K , str , n+1 )  
//       PUT  str[n] = '1'
//            GenerateAllString ( K , str , n+1 )
// Second Generate all binary string starts with '1'
// DO THE SAME PROCESS