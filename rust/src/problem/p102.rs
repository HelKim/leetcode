use std::rc::Rc;
use std::cell::RefCell;
use crate::base::tree_node::TreeNode;
use std::collections::VecDeque;

struct Solution {}

impl Solution {
    pub fn level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut result = vec![];
        if root.is_none() {
            return result
        }

        let mut q = VecDeque::new();
        q.push_back(root);

        while q.len() != 0 {
            let mut node_vec = vec![];
            let mut val_vec = vec![];

            while q.len() != 0 {
                let node = q.pop_front().unwrap().unwrap();
                val_vec.push(node.borrow().val);
                node_vec.push(node);
            }

            result.push(val_vec);

            for i in &node_vec {
                let mut node = i;
                if !node.borrow().left.is_none() {
                    q.push_back(node.borrow_mut().left.take());
                }

                if !node.borrow().right.is_none() {
                    q.push_back(node.borrow_mut().right.take());
                }
            }
        }

        result
    }
}