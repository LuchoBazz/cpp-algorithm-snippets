// Left and Right Boundary: https://www.pluralsight.com/guides/algorithm-templates:-two-pointers-part-2

// Img: https://i.imgur.com/xS5ZHoY.png

// sequence:  [a1, a2, a3, a4, ..., an]
//     [left] ->->              <-<-<- [right]

// int left=0, right=n-1;
// while(left < right) {
//     if(left_condition(left)) {
//         left++;
//     }
//     if(right_condition(right)) {
//         right--;
//     }
//     process_logic(left, right);
// }