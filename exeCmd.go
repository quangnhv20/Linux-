package main
import "fmt"
func main(){
    cmd := "mkdir -p /dump"
    _, err := exec.Command("bash","-c",cmd).Output()
   if err != nil {
       log.Fatal(err)
   }
}
