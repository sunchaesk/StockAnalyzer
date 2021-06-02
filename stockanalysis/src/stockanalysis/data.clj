(ns stockanalysis.data)
(load-file "src/stockanalysis/utils.clj")

(defstruct data
  :datetime
  :open
  :high
  :low
  :close
  :volume)

(defn read-file [filename]
  (slurp filename))

(defn split-by-newline [s]
  (clojure.string/split s #"\n"))

(defstruct data
  :datetime
  :open
  :high
  :low
  :close
  :volume)

;; To data
(defn line-to-data [s]
  (let [temp (clojure.string/split s #";")]
    (struct data
            (nth temp 0)
            (nth temp 1)
            (nth temp 2)
            (nth temp 3)
            (nth temp 4)
            (nth temp 5))))

(defn file-to-data [filename]
  (let [file (read-file filename)
        splited-file (split-by-newline file)]
    (map line-to-data splited-file)))

(defn frame-data [len data]
  (partition len 1 data))

(defn get-avg-data [data-l]
  (let [temp-nums (map :close data-l)
        nums (map stockanalysis.utils/String->Number temp-nums)]
    (stockanalysis.utils/average nums)))

;; uses data from frame-data
(defn step-data [data]
  (if (empty? data)
    nil
    (do
     (printf "%g\n" (get-avg-data (first data)))
     (step-data (rest data)))))

;; (def test-l (file-to-data "../data/msft.txt"))
;; (def test-l2 (frame-data 3 test-l))

;; (step-data test-l2)

;;;;;; NOT DONE
(defn read-main-loop [filename]
  (let [data (file-to-data filename)]
    (step-data (nth 0 data))))
