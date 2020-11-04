#lang planet neil/sicp

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

(define (goodEnough? guess x)
  (< (abs (- (cube guess)
             x))
     0.001))

(define (cuberoot-itr guess x)
  (if (goodEnough? guess x)
      guess
      [cuberoot-itr (improve guess x) x]))

(define (cubeRoot guess)
  (cuberoot-itr 13 guess))



(cube 10)
(improve 10 1000)
(abs -110)
(goodEnough? 1011 1000)
(cuberoot-itr 101 1000)
(cubeRoot 1000)

