package com.manni;

/**
 * 
 * @date 2014-04-12
 * @author fei.cheng
 *
 */

public class PriorityQueue {
    private int[] Q;
    private int capacity;

    public PriorityQueue(int initialCapacity) {
        Q = new int[initialCapacity+1];
        Q[0] = 0;
        this.capacity = initialCapacity;
    }
    
    public int size() {
        return Q[0];
    }
    
    public int capacity() {
        return capacity;
    }
    
    public int top() {
        if (Q[0] == 0) {
            System.out.println("Empty queue, no element.");
            System.exit(-1);
        }
        return Q[1];
    }

    public int pop() {
        if (Q[0] == 0) {
            System.out.println("Empty queue, no element.");
            System.exit(-1);
        }
        int value = Q[1];
        Q[1] = Q[Q[0]--];
        shiftdown(Q[0]);
        return value;
    }
    
    public void push(int value) {
        if (Q[0] == capacity()) {
            Q = enlargeCapacity();
        }
        Q[++Q[0]] = value;
        shiftup(Q[0]);
    }
    
    private int[] enlargeCapacity() {
        this.capacity = 2 * Q[0] + 1;
        int[] new_Q = new int[capacity];
        for(int i = 0; i <= Q[0]; ++i) {
            new_Q[i] = Q[i];
        }
        return new_Q;
    }
    
    private void swap(int i, int j) {
        int tmp = Q[i];
        Q[i] = Q[j];
        Q[j] = tmp;
    }
    
    private void shiftdown(int n) {
        int idx = 1;
        while (2*idx <= n) {
            int left = 2*idx;
            int right = left+1;
            int son = left;
            if ((right <= n) && (Q[right] < Q[left])) {
                son = right;
            }
            if(Q[idx] > Q[son]) {
                swap(idx, son);
                idx = son;
            } else {
                break;
            }
        }
    }
    
    private void shiftup(int n) {
        int idx = n;
        while (idx/2 >= 1) {
            int father = idx/2;
            if (Q[idx] < Q[father]) {
                swap(idx, father);
                idx = father;
            } else {
                break;
            }
        }
    }
}


class Test {
    public static void main(String[] args) {
        PriorityQueue pq = new PriorityQueue(4);
        
        pq.push(23);
        pq.push(10);
        pq.push(19);
        pq.push(25);
        pq.push(34);
        pq.push(85);
        pq.push(88);
        
        System.out.println(pq.pop());
        System.out.println(pq.pop());
        System.out.println(pq.pop());
        System.out.println(pq.pop());
        System.out.println(pq.pop());
        System.out.println(pq.pop());
        System.out.println(pq.pop());
        System.out.println(pq.pop());
    }
}
