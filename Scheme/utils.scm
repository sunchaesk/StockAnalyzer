(use-modules (ice-9 regex)
             (ice-9 rdelim))

(define (list-ref lst n)
 (if (<= n 0)
     (car lst)
     (list-ref (cdr lst) (- n 1))))
