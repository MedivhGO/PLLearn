#lang planet neil/sicp

; name can't contain capital letter

(define (cube x)
  (* x x x))

(define (improve y x)
  (/ (+ (/ x (* y y))
    (* 2 y)) 
    3))

(define (abs x)
  (if (> x 0)
    x
    [- 0 x]))

(define (good-enough? guess x)
  (< (abs (- (cube guess)
    x))
    0.001))

(define (cuberoot-itr guess x)
  (if (good-enough? guess x)
    guess
    [cuberoot-itr (improve guess x) x]))

(define (cuberoot guess)
  (cuberoot-itr 13 guess))

(cube 10)              ; 1000
(improve 10 1000)      ; 10
(abs -110)             ; 110
(good-enough? 1011 1000); #f
(cuberoot-itr 101 1000); pass
(cuberoot 1000)        ; pass