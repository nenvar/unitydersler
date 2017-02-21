using UnityEngine;
using System.Collections;

public class karkateraudio : MonoBehaviour {

    public AudioClip playerhurt;
    AudioSource playeraudio;


	void Start () {

     playeraudio = GetComponent<AudioSource>();//kodun atandigi objedeki audiorsource

    }
	
	
	void Update ()
    {

       

	}

    void OnTriggerEnter2D()
    {
        
        if(karakter damage alirsa)
        {
        	playeraudio.clip = playerhurt;
        	playeraudio.Play();
        	//eger muzikte loop secenegi aktifse
        	playeraudio.PlayOneShot(playerhurt); // bir kere calar
		}    
        
    }

}
