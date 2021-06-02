(ns stockanalysis.core
  (:gen-class))
(load-file "src/stockanalysis/utils.clj")
(load-file "src/stockanalysis/data.clj")
;; (load-file "src/stockanalysis/portfolio.clj")

(defstruct portfolio
  :curr-stock
  :start-stock
  :stock-cnt
  :start-date
  :current-portfolio
  :start-portfolio)

(defn -main
  "I don't do a whole lot ... yet."
  [& args]
  (read-file "../data/msft.txt"))
