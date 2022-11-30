use std::collections::HashMap;
use std::collections::HashSet;

impl Solution {
    pub fn unique_occurrences(arr: Vec<i32>) -> bool {
        let mut map = HashMap::new();

        for n in arr {
            let mut v = map.entry(n).or_insert(0);
            *v += 1;
        }

        let set: HashSet<i32> = map.values().copied().collect();

        set.len() == map.len()
    }
}
