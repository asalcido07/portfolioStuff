require('rspec')
require('leap_year')

describe('Fixnum#leap_year?') do
   it("is false for a year not divisible by 4") do
    expect(1993.leap_year?()).to(eq(false))
  end

  it("is true for most years divisible by 4") do
    expect(2004.leap_year?()).to(eq(true))  
  end
end