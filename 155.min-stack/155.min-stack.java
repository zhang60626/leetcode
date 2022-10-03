//Design a stack that supports push, pop, top, and retrieving the minimum 
//element in constant time. 
//
// Implement the MinStack class: 
//
// 
// MinStack() initializes the stack object. 
// void push(int val) pushes the element val onto the stack. 
// void pop() removes the element on the top of the stack. 
// int top() gets the top element of the stack. 
// int getMin() retrieves the minimum element in the stack. 
// 
//
// You must implement a solution with O(1) time complexity for each function. 
//
// 
// Example 1: 
//
// 
//Input
//["MinStack","push","push","push","getMin","pop","top","getMin"]
//[[],[-2],[0],[-3],[],[],[],[]]
//
//Output
//[null,null,null,null,-3,null,0,-2]
//
//Explanation
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin(); // return -3
//minStack.pop();
//minStack.top();    // return 0
//minStack.getMin(); // return -2
// 
//
// 
// Constraints: 
//
// 
// -2³¹ <= val <= 2³¹ - 1 
// Methods pop, top and getMin operations will always be called on non-empty 
//stacks. 
// At most 3 * 10⁴ calls will be made to push, pop, top, and getMin. 
// 
//
// Related Topics Stack Design 👍 9737 👎 680


//leetcode submit region begin(Prohibit modification and deletion)
class MinStack {
    private int[] elementData;
    private int[] minElementData;
    private int size;

    public MinStack() {
        elementData = new int[40000];
        minElementData = new int[40000];
        size = 0;
    }

    public void push(int val) {
        elementData[size] = val;
        if (size == 0) {
            minElementData[size] = val;
        } else {
            minElementData[size] = Integer.min(val, minElementData[size - 1]);
        }
        size++;
    }
    
    public void pop() {
        size--;
    }
    
    public int top() {
        return elementData[size - 1];
    }
    
    public int getMin() {
        return minElementData[size - 1];
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
//leetcode submit region end(Prohibit modification and deletion)
