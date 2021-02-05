// Sliding Windows

// Img: https://i.imgur.com/xS5ZHoY.png

// sequence: [a1, a2, a3, a4, a5, a6, a7,  ..., an]
//                |<- sliding window ->|
//                v                    v 
//             [start]-->            [end]-->

// int n = (int) any.size();
// int start=0, end=0;
// map<int, int> counter;
// int ans = 0;
// while(end < n) {
//     counter[any[end]]++;
//     while(condition(start, end) && start <= end) {
//         counter[any[start]]--;
//         process_logic1(start,end);
//         start++;
//     }
//     process_logic2(start,end);
//     ans = max(ans, end - start + 1);
//     end++;
// }
// print(ans);