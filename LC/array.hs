import Data.Array

myArray :: Array Int String
myArray = array (1, 5) [(1, "one"), (2, "two"), (3, "three"), (4, "four"), (5, "five")]

main :: IO ()
main = do
    print $ myArray ! 3
    print $ elems myArray
