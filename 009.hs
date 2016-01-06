-- RandomUsername (Nikola Jovanovic)
-- Project Euler
-- 009

specialPyth :: (Int, Int, Int, Int)
specialPyth = head [(a, b, 1000-a-b, a * b * (1000-a-b)) | a <- [1..], b <- [1..a], a*a == b*b + (1000-a-b)*(1000-a-b)]

main = do
    print specialPyth
