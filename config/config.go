package config

type Config struct {
	Packages []Package `yaml:"packages"`
	Jzero    Jzero     `yaml:"jzero"`
}

type Package struct {
	Name  string   `yaml:"name"`
	Paths []string `yaml:"paths"`
}

type Jzero struct {
	App    string `yaml:"app"`
	Branch string `yaml:"branch"`
}
