use std::rc::Rc;
use std::cell::RefCell;
use crate::base::tree_node::TreeNode;
use std::collections::VecDeque;

struct Solution {}

impl Solution {
    pub fn level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = vec!(vec!());
        if root == None {
            return result;
        }

        let mut q: VecDeque<Option<Rc<RefCell<TreeNode>>>> = VecDeque::new();
    }
}