"use client"

import { useState } from "react"
import { Button } from "@/components/ui/button"
import { Input } from "@/components/ui/input"
import { Label } from "@/components/ui/label"
import { Card, CardHeader, CardTitle, CardDescription, CardContent, CardFooter } from "@/components/ui/card"
import { Tabs, TabsContent, TabsList, TabsTrigger } from "@/components/ui/tabs"

export default function CombinedExercises() {
  const [dateValue, setDateValue] = useState("")
  const [factorialResult, setFactorialResult] = useState("")
  const [multiplicationTable, setMultiplicationTable] = useState("")

  const displayDate = () => {
    const today = new Date()
    const date = today.getDate()
    const month = today.getMonth() + 1
    const year = today.getFullYear()
    setDateValue(`${year}-${month.toString().padStart(2, "0")}-${date.toString().padStart(2, "0")}`)
  }

  const calculateFactorial = () => {
    const n = Number.parseInt(prompt("Enter a number: ") || "0")
    if (!isNaN(n)) {
      let factorial = 1
      for (let i = 1; i <= n; i++) {
        factorial *= i
      }
      setFactorialResult(`Factorial of ${n} is ${factorial}`)
    } else {
      setFactorialResult("Please enter a valid number.")
    }
  }

  const generateTable = () => {
    const n = Number.parseInt(prompt("Enter a number: ") || "0")
    if (!isNaN(n)) {
      let table = ""
      for (let i = 1; i <= 10; i++) {
        table += `${n} x ${i} = ${n * i}\n`
      }
      setMultiplicationTable(table)
    } else {
      setMultiplicationTable("Please enter a valid number.")
    }
  }

  return (
    <div className="min-h-screen bg-gray-900 text-gray-100 p-8">
      <header className="text-center mb-8">
        <h1 className="text-3xl font-bold">Shreyans Tatiya</h1>
        <p className="text-gray-400">Roll Number: 16010123325</p>
      </header>

      <Tabs defaultValue="registration" className="max-w-2xl mx-auto">
        <TabsList className="grid w-full grid-cols-4">
          <TabsTrigger value="registration">Registration</TabsTrigger>
          <TabsTrigger value="multiplication">Multiplication</TabsTrigger>
          <TabsTrigger value="date">Date</TabsTrigger>
          <TabsTrigger value="factorial">Factorial</TabsTrigger>
        </TabsList>

        <TabsContent value="registration">
          <Card>
            <CardHeader>
              <CardTitle>Registration Form</CardTitle>
              <CardDescription>Enter your details to register.</CardDescription>
            </CardHeader>
            <CardContent>
              <form className="space-y-4">
                <div className="space-y-2">
                  <Label htmlFor="name">Name</Label>
                  <Input id="name" required />
                </div>
                <div className="space-y-2">
                  <Label htmlFor="password">Password</Label>
                  <Input id="password" type="password" required />
                </div>
                <div className="space-y-2">
                  <Label htmlFor="email">Email</Label>
                  <Input id="email" type="email" required />
                </div>
                <div className="space-y-2">
                  <Label htmlFor="phone">Phone</Label>
                  <Input id="phone" type="tel" required />
                </div>
              </form>
            </CardContent>
            <CardFooter>
              <Button>Register</Button>
            </CardFooter>
          </Card>
        </TabsContent>

        <TabsContent value="multiplication">
          <Card>
            <CardHeader>
              <CardTitle>Multiplication Table</CardTitle>
              <CardDescription>Generate a multiplication table.</CardDescription>
            </CardHeader>
            <CardContent>
              <Button onClick={generateTable}>Generate Table</Button>
              {multiplicationTable && (
                <pre className="mt-4 p-4 bg-gray-800 rounded-md overflow-x-auto">{multiplicationTable}</pre>
              )}
            </CardContent>
          </Card>
        </TabsContent>

        <TabsContent value="date">
          <Card>
            <CardHeader>
              <CardTitle>Display Date</CardTitle>
              <CardDescription>Show the current date.</CardDescription>
            </CardHeader>
            <CardContent>
              <div className="flex space-x-2">
                <Input value={dateValue} readOnly />
                <Button onClick={displayDate}>Display Date</Button>
              </div>
            </CardContent>
          </Card>
        </TabsContent>

        <TabsContent value="factorial">
          <Card>
            <CardHeader>
              <CardTitle>Factorial Calculator</CardTitle>
              <CardDescription>Calculate the factorial of a number.</CardDescription>
            </CardHeader>
            <CardContent>
              <Button onClick={calculateFactorial}>Calculate Factorial</Button>
              {factorialResult && <p className="mt-4">{factorialResult}</p>}
            </CardContent>
          </Card>
        </TabsContent>
      </Tabs>
    </div>
  )
}

