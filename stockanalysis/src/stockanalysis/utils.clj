(ns stockanalysis.utils)

(defn average [nums]
  (if (empty? nums)
    0
    (/ (reduce + nums) (count nums))))

(defn String->Number [str]
  (let [n (read-string str)]
       (if (number? n) n nil)))
