import Control.Monad
import Control.Monad.ST
import Data.Array.ST
import Data.Array.Unboxed
import Data.Array.MArray
import Data.ByteString.Char8 as BS

solve :: Int -> STUArray s Int Int -> Int
solve n
