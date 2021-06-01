
(use-modules (ice-9 regex)
             (ice-9 rdelim))
(include "utils.scm")

;; 2021-03-12;234.00999;235.82001;233.23000;235.75000;22647900
(define data  (make-record-type "data "'(datetime
                                         open
                                         high
                                         low
                                         close
                                         volume)))
(define make-data (record-constructor data '(datetime
                                             open
                                             high
                                             low
                                             close
                                             volume)))
(define get-data-datetime (record-accessor data 'datetime))
(define get-data-open (record-accessor data 'open))
(define get-data-high (record-accessor data 'high))
(define get-data-low (record-accessor data 'low))
(define get-data-close (record-accessor data 'close))
(define get-data-volume (record-accessor data 'volume))

;; 2021-03-12;234.00999;235.82001;233.23000;235.75000;22647900
(define (to-data s)
  (let ((l (split-semi s)))
    (make-data (list-ref l 0)
               (list-ref l 1)
               (list-ref l 2)
               (list-ref l 3)
               (list-ref l 4)
               (list-ref l 5))))
