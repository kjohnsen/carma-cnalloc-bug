from pymod import StaticMC, DynamicMC

def test_SMC():
    StaticMC(100)
    print("SMC success")

def test_DMC():
    DynamicMC(100, True)  # large vector doesn't crash
    DynamicMC(2, False)  # small Matrix doesn't crash
    print("worked up to here, but should crash before displaying `DMC success`")
    DynamicMC(100, False)  # large Matrix does: you won't see success here
    print("DMC success")

