using System;
namespace Refleksja
{
	class Program
	{
		static void Main(string[] args)
		{
			System.Reflection.MemberInfo info = typeof(MyClassToGetAttributeInfo);
			// pobranie listy atrybutów
			object[] attributes = info.GetCustomAttributes(true);
			for (int i = 0; i < attributes.Length; i++)
			{
				// Wypisujemy wszystkie atrybuty
				Console.WriteLine(attributes[i]);
				// Dodatkowo uzyskamy dostęp do opisu naszego atrybutu
				ExampleAttribute ea = (ExampleAttribute)attributes[i];
				Console.WriteLine("Info: {0}", ea.message);
			}
			Console.ReadKey();
			// Wynik działania programu
			// Refleksja.ExampleAttribute
			// Info: Informacja o mojej klasie
		}
	}
	[AttributeUsage(AttributeTargets.All)]
	public class ExampleAttribute : Attribute
	{
		public readonly string message;
		private string topic;
		public ExampleAttribute(string Message)
		{
			this.message = Message;
		}
		public string Topic
		{
			get
			{
				return topic;
			}
			set
			{
				topic = value;
			}
		}
	}
	[ExampleAttribute("Informacja o mojej klasie")]
	class MyClassToGetAttributeInfo
	{
	}
}