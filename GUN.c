using UnityEngine;
using System.Collections;

public class gun : MonoBehaviour {

    // Use this for initialization
    public GameObject mermi;
    public Transform silah;
    karakter karakterscript;


	void Start ()
    {
        karakterscript = GameObject.Find("player").GetComponent<karakter>(); //player olarak olusturdugumuz gameobjesini bulup, componentlerinden karakter scriptine ulasiyoruz
    }
	
	// Update is called once per frame
	void Update ()
    {
	    if(Input.GetButtonDown("Fire1")&&karakterscript.flipside == false)
        {
            Instantiate(mermi, silah.position, Quaternion.Euler (new Vector3(0, 0, -90)));
        }
        if (Input.GetButtonDown("Fire1") && karakterscript.flipside == true)
        {
            Instantiate(mermi, silah.position, Quaternion.Euler(new Vector3(0, 0, 90)));
        }
    }
}
